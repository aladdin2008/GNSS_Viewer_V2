#pragma once


// CCon_register ��ܤ��

class CCon_register : public CDialog
{
	DECLARE_DYNAMIC(CCon_register)

public:
	CCon_register(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CCon_register();
	
	CString m_addr;
	CString m_data;

	CEdit m_txt_addr;
	CEdit m_txt_data;
// ��ܤ�����
	enum { IDD = IDD_CON_REGISTER };
  int  specialFunction;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnEnUpdateRegAddr();
};
