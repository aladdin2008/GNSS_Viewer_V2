#pragma once
#include "afxwin.h"

	
// CConBinOutDlg ��ܤ��

class CConBinOutDlg : public CDialog
{
	DECLARE_DYNAMIC(CConBinOutDlg)

public:
	CConBinOutDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConBinOutDlg();

// ��ܤ�����
	enum { IDD = IDD_CFG_BIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	CButton m_ecef;
	CButton m_pvt;
	CButton m_sat;
	CButton m_meas;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();	
};
