// TTYDoc.h : interface of the CTTYDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TTYDOC_H__E5640313_0AED_4111_A859_25905A489350__INCLUDED_)
#define AFX_TTYDOC_H__E5640313_0AED_4111_A859_25905A489350__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//����������ݿ顢XON��XOFF
#define MAXBLOCK 4096
#define XON 0x11
#define XOFF 0x13

UINT ComProc(LPVOID pParam);	//

class CTTYDoc : public CDocument
{
protected: // create from serialization only
	CTTYDoc();
	DECLARE_DYNCREATE(CTTYDoc)

// Attributes
public:
	CWinThread* m_pThread; // �������߳�
	volatile BOOL m_bConnected;//��ʾ���ӷ�������ʶ�˵��������ӺͶϿ������Ƿ����
	volatile HWND m_hTermWnd;//��������
	volatile HANDLE m_hPostMsgEvent; // ����WM_COMMNOTIFY��Ϣ���¼�����
	OVERLAPPED m_osRead, m_osWrite; // �����ص���/д

	volatile HANDLE m_hCom; // ���пھ��
	int m_nBaud;//���ݴ�������
	int m_nDataBits;//����λ
	BOOL m_bEcho;//�������ػ���
	BOOL m_bNewLine;//�����Զ�����
	int m_nParity;//У��λ
	CString m_sPort;//���ж˿�
	int m_nStopBits;//ֹͣλ

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTTYDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL CanCloseFrame(CFrameWnd* pFrame);
	//}}AFX_VIRTUAL

// Implementation
public:
	void CloseConnection();//�ر�����
	BOOL OpenConnection();//�򿪴���
	BOOL ConfigConnection();//��������
	DWORD ReadComm(char *buf,DWORD dwLength);//������
	DWORD WriteComm(char *buf,DWORD dwLength);//д����
	virtual ~CTTYDoc();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTTYDoc)
	afx_msg void OnApiConnect();
	afx_msg void OnUpdateApiConnect(CCmdUI* pCmdUI);
	afx_msg void OnApiDisconnect();
	afx_msg void OnUpdateApiDisconnect(CCmdUI* pCmdUI);
	afx_msg void OnApiSettings();
	afx_msg void OnUpdateApiSettings(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TTYDOC_H__E5640313_0AED_4111_A859_25905A489350__INCLUDED_)

