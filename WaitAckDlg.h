#pragma once
#include "afxwin.h"


// CWaitAckDlg ��ܤ��

class CWaitAckDlg : public CDialog
{
	DECLARE_DYNAMIC(CWaitAckDlg)

public:
	CWaitAckDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CWaitAckDlg();

// ��ܤ�����
	enum { IDD = IDD_WAITACK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:	
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	bool IsFinish;
	CEdit m_msg;
	
};
