#pragma once
#include "afxwin.h"


// CConSrePorDlg ��ܤ��

class CConSrePorDlg : public CDialog
{
	DECLARE_DYNAMIC(CConSrePorDlg)

public:
	CConSrePorDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConSrePorDlg();

// ��ܤ�����
	enum { IDD = IDD_CON_SRE_POR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comport;
	CComboBox m_baudrate;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	U08 messages[10];  
	CComboBox m_attribute;
};
