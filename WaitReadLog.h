#pragma once

//#include "GPSDlg.h"

// CWaitReadLog ��ܤ��

class CWaitReadLog : public CDialog
{
	DECLARE_DYNAMIC(CWaitReadLog)

public:
	CWaitReadLog(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CWaitReadLog();

// ��ܤ�����
//	enum { IDD = IDD_WAITLOGREAD };

//	CGPSDlg *pdlg;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	CEdit msg;
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	bool IsFinish;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
};
