#pragma once
#include "afxwin.h"


// CSetFilterDlg ��ܤ��

class CSetFilterDlg : public CDialog
{
	DECLARE_DYNAMIC(CSetFilterDlg)

public:
	CSetFilterDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CSetFilterDlg();

// ��ܤ�����
	enum { IDD = IDD_DLGSETFILTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_tmin;
	CEdit m_tmax;
	CEdit m_dmin;
	CEdit m_dmax;
	CEdit m_vmin;
	CEdit m_vmax;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
