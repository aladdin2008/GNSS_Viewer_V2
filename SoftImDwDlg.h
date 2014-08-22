#pragma once

// CSoftImDwDlg ��ܤ��
#define UWM_SETTIMEOUT		(WM_USER + 0x0062)
#define UWM_SETPROGRESS		(WM_USER + 0x0005)
#define UWM_SETPROMPT_MSG	(WM_USER + 0x0019)

class CSoftImDwDlg : public CDialog
{
	DECLARE_DYNAMIC(CSoftImDwDlg)

public:
	CSoftImDwDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CSoftImDwDlg();

// ��ܤ�����
	enum { IDD = IDD_SOFTWAREIMAGEDOWNLOAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg  LRESULT OnSetTimeout(WPARAM wParam, LPARAM lParam);
	afx_msg  LRESULT OnSetProgress(WPARAM wParam, LPARAM lParam);
	afx_msg  LRESULT OnSetPromptMessage(WPARAM wParam, LPARAM lParam);

public:
	void SetFinish(bool finish) { isFinish = finish; }
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnClose();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	CProgressCtrl m_progress;	
	bool isFinish;
	
	CEdit m_msg;
	CEdit m_percent;
//	CButton m_close ;
};
