#pragma once


// CCon_acquisition ��ܤ��

class CCon_acquisition : public CDialog
{
	DECLARE_DYNAMIC(CCon_acquisition)

public:
	CCon_acquisition(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CCon_acquisition();

// ��ܤ�����
	enum { IDD = IDD_CFG_ACQUISITION_MODE };

	int mode;
	int auto_power_off;
	int attr;

	CComboBox cbo_auto_power_off,cbo_auto_power_off_ascii;
	CButton rdo_binary,rdo_ascii;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
