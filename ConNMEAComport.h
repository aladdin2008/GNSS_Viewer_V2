#pragma once
#include "afxwin.h"


// CConNMEAComport ��ܤ��

class CConNMEAComport : public CDialog
{
	DECLARE_DYNAMIC(CConNMEAComport)

public:
	CConNMEAComport(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConNMEAComport();

// ��ܤ�����
	enum { IDD = IDD_CON_NMEA_COMPORT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CButton m_com0;
	CButton m_com1;
	int comport;
	int attr;
	afx_msg void OnBnClickedOk();
};
