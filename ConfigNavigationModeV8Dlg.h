#pragma once


// ConfigNavigationModeV8Dlg ��ܤ��

class ConfigNavigationModeV8Dlg : public CDialog
{
	DECLARE_DYNAMIC(ConfigNavigationModeV8Dlg)

public:
	ConfigNavigationModeV8Dlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~ConfigNavigationModeV8Dlg();

// ��ܤ�����
//	enum { IDD = IDD_CONFIG_NAV_MODE_V8 };
	int m_nMode;
	int m_nAttribute;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
