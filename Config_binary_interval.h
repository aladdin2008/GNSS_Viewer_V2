#pragma once


// CConfig_binary_interval ��ܤ��

class CConfig_binary_interval : public CDialog
{
	DECLARE_DYNAMIC(CConfig_binary_interval)

public:
	CConfig_binary_interval(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfig_binary_interval();

// ��ܤ�����
	enum { IDD = IDD_CONFIG_BINARY_INTERVAL };

	CComboBox m_interval,m_attr;
	int m_bin_interval,m_bin_attr;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
