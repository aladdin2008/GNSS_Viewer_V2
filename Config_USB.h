#pragma once

#if WITH_CONFIG_USB_BAUDRATE
// CConfig_USB ��ܤ��

class CConfig_USB : public CDialog
{
	DECLARE_DYNAMIC(CConfig_USB)

public:
	CConfig_USB(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfig_USB();

	CComboBox m_Devices;

	BAUD_CONFIG_DATA	m_DefaultBaudConfigData;

	BAUD_CONFIG_DATA m_ROM_BaudConfigData;

	HANDLE	m_DeviceHandle;
// ��ܤ�����
	enum { IDD = IDD_CFG_USB };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRefresh();
	afx_msg void OnBnClickedUsedRom();
	afx_msg void OnBnClickedUsedFlash();
};

#endif