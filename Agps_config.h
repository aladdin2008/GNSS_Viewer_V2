#pragma once

#include "resource.h"

// CAgps_config ��ܤ��

class CAgps_config : public CDialog
{
	DECLARE_DYNAMIC(CAgps_config)

public:
	CAgps_config(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CAgps_config();

// ��ܤ�����
	enum { IDD = IDD_AGPS_CONFIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int enable;
	int attribute;
	CComboBox cbo_status;
	virtual BOOL OnInitDialog();
	void Set_Enable(U08 enable);
};
