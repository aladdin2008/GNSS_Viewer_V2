#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CConDauDlg ��ܤ��

class CConDauDlg : public CDialog
{
	DECLARE_DYNAMIC(CConDauDlg)

public:
	CConDauDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConDauDlg();

// ��ܤ�����
	enum { IDD = IDD_CON_DATUM };

	CButton m_test;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ellipsoidlist;
	virtual BOOL OnInitDialog();	
	afx_msg void OnBnClickedOk();
	CComboBox m_attribute;
	afx_msg void OnBnClickedDatumTest();
};
