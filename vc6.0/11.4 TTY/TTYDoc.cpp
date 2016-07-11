// TTYDoc.cpp : implementation of the CTTYDoc class
//

#include "stdafx.h"
#include "TTY.h"
#include "commsetDlg.h"
#include "TTYDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTTYDoc

IMPLEMENT_DYNCREATE(CTTYDoc, CDocument)

BEGIN_MESSAGE_MAP(CTTYDoc, CDocument)
	//{{AFX_MSG_MAP(CTTYDoc)
	ON_COMMAND(ID_API_CONNECT, OnApiConnect)
	ON_UPDATE_COMMAND_UI(ID_API_CONNECT, OnUpdateApiConnect)
	ON_COMMAND(ID_API_DISCONNECT, OnApiDisconnect)
	ON_UPDATE_COMMAND_UI(ID_API_DISCONNECT, OnUpdateApiDisconnect)
	ON_COMMAND(ID_API_SETTINGS, OnApiSettings)
	ON_UPDATE_COMMAND_UI(ID_API_SETTINGS, OnUpdateApiSettings)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CTTYDoc construction/destruction

CTTYDoc::CTTYDoc()
{
	// TODO: add one-time construction code here
//��ʼ������
	m_bConnected=FALSE;//�Ͽ����Ӳ˵�����Ч
	m_pThread=NULL;

	m_nBaud = 9600;
	m_nDataBits = 8;
	m_bEcho = FALSE;
	m_bNewLine = FALSE;
	m_nParity = 0;
	m_sPort = "COM2";
	m_nStopBits = 0;
}

CTTYDoc::~CTTYDoc()
{
//�������ʱɾ���̡߳��رմ��ڵĲ���
	if(m_bConnected)
		CloseConnection();

	// ɾ���¼����
	if(m_hPostMsgEvent)
		CloseHandle(m_hPostMsgEvent);

	if(m_osRead.hEvent)
		CloseHandle(m_osRead.hEvent);

	if(m_osWrite.hEvent)
		CloseHandle(m_osWrite.hEvent);
}

BOOL CTTYDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	
	// ΪWM_COMMNOTIFY��Ϣ�����¼������ֹ����ã���ʼ��Ϊ���źŵ�
	if((m_hPostMsgEvent=CreateEvent(NULL, TRUE, TRUE, NULL))==NULL)
		return FALSE;

	memset(&m_osRead, 0, sizeof(OVERLAPPED));
	memset(&m_osWrite, 0, sizeof(OVERLAPPED));

	// Ϊ�ص��������¼������ֹ����ã���ʼ��Ϊ���źŵ�
	if((m_osRead.hEvent=CreateEvent(NULL, TRUE, FALSE, NULL))==NULL)
		return FALSE;

	// Ϊ�ص�д�����¼������ֹ����ã���ʼ��Ϊ���źŵ�
	if((m_osWrite.hEvent=CreateEvent(NULL, TRUE, FALSE, NULL))==NULL)
		return FALSE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CTTYDoc serialization

void CTTYDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CTTYDoc diagnostics

#ifdef _DEBUG
void CTTYDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTTYDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTTYDoc commands

BOOL CTTYDoc::CanCloseFrame(CFrameWnd* pFrame) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	SetModifiedFlag(FALSE); // ���ĵ����޸ı�־���ó�δ�޸�
	return CDocument::CanCloseFrame(pFrame);
}

// �������̣߳�������Ӵ��п�
UINT CommProc(LPVOID pParam)
{
	OVERLAPPED os;
	DWORD dwMask, dwTrans;
	COMSTAT ComStat;
	DWORD dwErrorFlags;

	CTTYDoc *pDoc=(CTTYDoc*)pParam;

	memset(&os, 0, sizeof(OVERLAPPED));
	os.hEvent=CreateEvent(NULL, TRUE, FALSE, NULL);

	if(os.hEvent==NULL)
	{
		AfxMessageBox("Can't create event object!");
		return (UINT)-1;
	}

	while(pDoc->m_bConnected)
	{
		ClearCommError(pDoc->m_hCom,&dwErrorFlags,&ComStat);

		if(ComStat.cbInQue)
		{
			// ���޵ȴ�WM_COMMNOTIFY��Ϣ��������
			WaitForSingleObject(pDoc->m_hPostMsgEvent, INFINITE);
			ResetEvent(pDoc->m_hPostMsgEvent);

			// ֪ͨ��ͼ
			PostMessage(pDoc->m_hTermWnd, WM_COMMNOTIFY, EV_RXCHAR, 0);

			continue;
		}

		dwMask=0;

		if(!WaitCommEvent(pDoc->m_hCom, &dwMask, &os)) // �ص�����
		{

			if(GetLastError()==ERROR_IO_PENDING)
			// ���޵ȴ��ص��������
				GetOverlappedResult(pDoc->m_hCom, &os, &dwTrans, TRUE);
			else
			{
				CloseHandle(os.hEvent);
				return (UINT)-1;
			}
		}
	}

	CloseHandle(os.hEvent);
	return 0;
}

// ��ָ���������ַ��Ӵ��п����
DWORD CTTYDoc::WriteComm(char *buf, DWORD dwLength)
{
	BOOL fState;
	DWORD length=dwLength;
	COMSTAT ComStat;
	DWORD dwErrorFlags;

	ClearCommError(m_hCom,&dwErrorFlags,&ComStat);
	fState=WriteFile(m_hCom,buf,length,&length,&m_osWrite);

	if(!fState)
	{

		if(GetLastError()==ERROR_IO_PENDING)
		{
			GetOverlappedResult(m_hCom,&m_osWrite,&length,TRUE);// �ȴ�
		}
		else
			length=0;
	}

	return length;
}

// �Ӵ��п����뻺�����ж���ָ���������ַ�
DWORD CTTYDoc::ReadComm(char *buf, DWORD dwLength)
{
	DWORD length=0;
	COMSTAT ComStat;
	DWORD dwErrorFlags;

	ClearCommError(m_hCom,&dwErrorFlags,&ComStat);
	length=min(dwLength, ComStat.cbInQue);
	ReadFile(m_hCom,buf,length,&length,&m_osRead);

	return length;
}

//�˵���"��������"����Ӧ
void CTTYDoc::OnApiConnect() 
{
	// TODO: Add your command handler code here
	if(!OpenConnection())
		AfxMessageBox("Can't open connection");
}

//����"��������"�˵���
void CTTYDoc::OnUpdateApiConnect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_bConnected);
}

//�˵���"�Ͽ�����"����Ӧ����
void CTTYDoc::OnApiDisconnect() 
{
	// TODO: Add your command handler code here
	CloseConnection(); 
}

//���²˵���"�Ͽ�����"
void CTTYDoc::OnUpdateApiDisconnect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bConnected);
}

//�˵���"���п�����" ����Ӧ����
void CTTYDoc::OnApiSettings() 
{
	// TODO: Add your command handler code here
	CCommSetDlg dlg;
	CString str;

	dlg.m_bConnected = m_bConnected;

	dlg.m_sPort = m_sPort;

	str.Format("%d", m_nBaud);
	dlg.m_sBaud = str;

	str.Format("%d", m_nDataBits);
	dlg.m_sDataBits = str;

	dlg.m_nParity = m_nParity;
	
	dlg.m_nStopBits = m_nStopBits;
	
	dlg.m_bEcho = m_bEcho;
	dlg.m_bNewLine = m_bNewLine;

	if(dlg.DoModal() == IDOK)
	{
		m_sPort = dlg.m_sPort;
		m_nBaud = atoi(dlg.m_sBaud);
		m_nDataBits = atoi(dlg.m_sDataBits);
		m_nParity = dlg.m_nParity;
		m_nStopBits = dlg.m_nStopBits;
		
		m_bEcho=dlg.m_bEcho;
		m_bNewLine=dlg.m_bNewLine;

		if(m_bConnected)
			if(!ConfigConnection())
				AfxMessageBox("Can't realize the settings!");
	}
}

//����"���п�����"�˵���
void CTTYDoc::OnUpdateApiSettings(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}
 //���ô�������
BOOL CTTYDoc::ConfigConnection()
{
	DCB dcb;

	if(!GetCommState(m_hCom, &dcb))
		return FALSE;

	dcb.fBinary=TRUE;
	dcb.BaudRate = m_nBaud; // ���ݴ�������
	dcb.ByteSize = m_nDataBits; // ÿ�ֽ�λ��
	dcb.fParity = TRUE;

	switch(m_nParity) // У������
	{
	case 0: 
		dcb.Parity=NOPARITY;
		break;

	case 1: 
		dcb.Parity=EVENPARITY;
		break;

	case 2: 
		dcb.Parity=ODDPARITY;
		break;

	default:;
	}

	switch(m_nStopBits) // ֹͣλ
	{
	case 0: 
		dcb.StopBits=ONESTOPBIT;
		break;

	case 1: 
		dcb.StopBits=ONE5STOPBITS;
		break;

	case 2:
		dcb.StopBits=TWOSTOPBITS;
		break;

	default:;
	}

	// Ӳ������������
	dcb.fOutxCtsFlow = TRUE;
	dcb.fRtsControl = TRUE;

	// XON/XOFF����������
	dcb.fInX=dcb.fOutX = TRUE;
	dcb.XonChar = XON;
	dcb.XoffChar = XOFF;
	dcb.XonLim = 50;
	dcb.XoffLim = 50;

	return SetCommState(m_hCom, &dcb);
}

// �򿪲����ô��пڣ������������߳�
BOOL CTTYDoc::OpenConnection()
{
	COMMTIMEOUTS TimeOuts;
	POSITION firstViewPos;
	CView *pView;

	firstViewPos=GetFirstViewPosition();
	pView=GetNextView(firstViewPos);

	m_hTermWnd=pView->GetSafeHwnd();

	if(m_bConnected)
		return FALSE;

	m_hCom=CreateFile(m_sPort, GENERIC_READ | GENERIC_WRITE, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 
		NULL); // �ص���ʽ

	if(m_hCom==INVALID_HANDLE_VALUE)
		return FALSE;

	SetupComm(m_hCom,MAXBLOCK,MAXBLOCK);
	SetCommMask(m_hCom, EV_RXCHAR);


	// �Ѽ����ʱ��Ϊ��󣬰��ܳ�ʱ��Ϊ0������ReadFile�������ز���ɲ���
	TimeOuts.ReadIntervalTimeout=MAXDWORD; 
	TimeOuts.ReadTotalTimeoutMultiplier=0; 
	TimeOuts.ReadTotalTimeoutConstant=0; 

	/* ����д��ʱ��ָ��WriteComm��Ա�����е�GetOverlappedResult�����ĵȴ�ʱ��*/
	TimeOuts.WriteTotalTimeoutMultiplier=50;
	TimeOuts.WriteTotalTimeoutConstant=2000;

	SetCommTimeouts(m_hCom, &TimeOuts);

	if(ConfigConnection())
	{

		m_pThread=AfxBeginThread(CommProc, this, THREAD_PRIORITY_NORMAL, 
			0, CREATE_SUSPENDED, NULL); // �����������߳�

		if(m_pThread==NULL)
		{
			CloseHandle(m_hCom);
			return FALSE;
		}
		else

		{
			m_bConnected=TRUE;
			m_pThread->ResumeThread(); // �ָ��߳�����
		}
	}
	else
	{
		CloseHandle(m_hCom);
		return FALSE;
	}
	
	return TRUE;
}

//�ر����ӣ��رչ����߳�
void CTTYDoc::CloseConnection()
{
	if(!m_bConnected)
		return;

	m_bConnected=FALSE;

	//����CommProc�߳���WaitSingleObject�����ĵȴ�
	SetEvent(m_hPostMsgEvent); 

	//����CommProc�߳���WaitCommEvent�ĵȴ�
	SetCommMask(m_hCom, 0); 

	//�ȴ������߳���ֹ
	WaitForSingleObject(m_pThread->m_hThread, INFINITE);
	m_pThread=NULL;
	CloseHandle(m_hCom);

}
