#pragma once
#include "afxwin.h"


// CCigRgsDlg ��ܤ��

class CCigRgsDlg : public CDialog
{
	DECLARE_DYNAMIC(CCigRgsDlg)

public:
	CCigRgsDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CCigRgsDlg();

// ��ܤ�����
	enum { IDD = IDD_CIGRGSDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_ms;
	CEdit m_ns;
	CEdit m_plldiv;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	U08 MS;
	U08 NS;
	U08 PLLDIV;
};
