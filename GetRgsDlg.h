#pragma once
#include "afxwin.h"


// CGetRgsDlg ��ܤ��

class CGetRgsDlg : public CDialog
{
	DECLARE_DYNAMIC(CGetRgsDlg)

public:
	CGetRgsDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CGetRgsDlg();

// ��ܤ�����
	enum { IDD = IDD_GETRGSDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_address;
	unsigned int address;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
