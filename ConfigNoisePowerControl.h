#pragma once


// CConfigNoisePowerControl ��ܤ��

class CConfigNoisePowerControl : public CDialog
{
	DECLARE_DYNAMIC(CConfigNoisePowerControl)

public:
	CConfigNoisePowerControl(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigNoisePowerControl();

// ��ܤ�����
//	enum { IDD = IDD_CONFIG_NOISE_PWR_CTRL };
	BOOL m_nMode;
	int m_nAttribute;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
