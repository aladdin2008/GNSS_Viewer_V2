#pragma once


// CSetupDialog ��ܤ��
struct Setting;

class CSetupDialog : public CDialog
{
	DECLARE_DYNAMIC(CSetupDialog)

public:
	CSetupDialog(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CSetupDialog();

// ��ܤ�����
//	enum { IDD = IDD_SETUP };

	void SetSetting(Setting* p)
	{ setting = p; }
protected:
	Setting* setting;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBrowse();
	virtual BOOL OnInitDialog();
};
