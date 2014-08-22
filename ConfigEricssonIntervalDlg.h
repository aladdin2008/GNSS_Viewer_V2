#pragma once

// ConfigEricssonIntervalDlg ��ܤ��

class ConfigEricssonIntervalDlg : public CDialog
{
	DECLARE_DYNAMIC(ConfigEricssonIntervalDlg)

public:
	ConfigEricssonIntervalDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~ConfigEricssonIntervalDlg();

// ��ܤ�����
	enum { IDD = IDD_CONFIG_ERICSSON_INTERVAL };


protected:
	CComboBox m_attr;
	U08 m_attrib;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
	virtual BOOL OnInitDialog();
	void AdjustValue(int nPos, CScrollBar* pScrollBar);

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedOk();

	DECLARE_MESSAGE_MAP()
public:
	U08 GetParam(int index);
	U08 GetAttribute()
	{
		return m_attrib;
	}

};

class ConfigSerialNumberDlg : public CDialog
{
	DECLARE_DYNAMIC(ConfigSerialNumberDlg)

public:
	ConfigSerialNumberDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~ConfigSerialNumberDlg();

// ��ܤ�����
	enum { IDD = IDD_CONFIG_SERIAL_NUMBER };

protected:
	CString strSn;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();

	DECLARE_MESSAGE_MAP()
public:
	void SendCommand();
	afx_msg void OnEnChangeSn();
};
