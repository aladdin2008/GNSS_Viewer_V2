#pragma once
#include "afxwin.h"


// CCfgMsg ��ܤ��

class CCfgMsg : public CDialog
{
	DECLARE_DYNAMIC(CCfgMsg)

public:
	CCfgMsg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CCfgMsg();

// ��ܤ�����
	enum { IDD = IDD_CFGMSG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	int msg_id;
	CComboBox m_type;
	CComboBox m_attribute;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
