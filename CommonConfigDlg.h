#pragma once


// CCommonConfigDlg ��ܤ��

class CCommonConfigDlg : public CDialog
{
	DECLARE_DYNAMIC(CCommonConfigDlg)

public:
	CCommonConfigDlg(UINT nIDTemplate, CWnd* pParent = NULL);
	virtual ~CCommonConfigDlg();

	virtual void DoCommand() = 0;

protected:
	DECLARE_MESSAGE_MAP()
};

// CConfigDGPS ��ܤ��
class CConfigDGPS : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigDGPS)
public:
	CConfigDGPS(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigDGPS() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

protected:
	BOOL m_bEnable;
	int m_nOverdueSeconds;
	int m_nAttribute;	
	
	DECLARE_MESSAGE_MAP()
};

// CConfigSmoothMode ��ܤ��
class CConfigSmoothMode : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigSmoothMode)
public:
	CConfigSmoothMode(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigSmoothMode() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

protected:
	BOOL m_bEnable;
	int m_nAttribute;	
	
	DECLARE_MESSAGE_MAP()
};

// CConfigTimeStamping ��ܤ��
class CConfigTimeStamping : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigTimeStamping)
public:
	CConfigTimeStamping(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigTimeStamping() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

protected:
	BOOL m_bEnable;
	BOOL m_bTiggerMode;
	int m_nAttribute;	
	
	DECLARE_MESSAGE_MAP()
};

// CConfigSBAS ��ܤ��
class CConfigSBAS : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigSBAS)
public:
	CConfigSBAS(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigSBAS() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedEnableWaas();
	afx_msg void OnBnClickedEnableEgnos();
	afx_msg void OnBnClickedEnableMasa();
	afx_msg void OnBnClickedEnableAll();

	virtual BOOL OnInitDialog();

protected:
	BOOL m_bEnable;
	BOOL m_bRanging;
	BOOL m_bCorrection;
	int m_nUraMask;
	int m_nTrackingChannel;
	BOOL m_bWAAS;
	BOOL m_bEGNOS;
	BOOL m_bMSAS;
	BOOL m_bAll;
	int m_nAttribute;

	DECLARE_MESSAGE_MAP()
};

// CConfigSAGPS ��ܤ��
class CConfigSAEE : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigSAEE)
public:
	CConfigSAEE(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigSAEE() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

protected:
	int m_nEnable;
	int m_nAttribute;

	DECLARE_MESSAGE_MAP()
};

// CConfigQZSS ��ܤ��
class CConfigQZSS : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigQZSS)
public:
	CConfigQZSS(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigQZSS() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

protected:
	BOOL m_bEnable;
	int m_nTrackingChannel;
	int m_nAttribute;

	DECLARE_MESSAGE_MAP()
};

// CConfigInterferenceDetectControl ��ܤ��
class CConfigInterferenceDetectControl : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigInterferenceDetectControl)
public:
	CConfigInterferenceDetectControl(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigInterferenceDetectControl() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

protected:
	BOOL m_nMode;
	int m_nAttribute;

	DECLARE_MESSAGE_MAP()
};

// CConfigNMEABinaryOutputDestination ��ܤ��
class CConfigNMEABinaryOutputDestination : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigNMEABinaryOutputDestination)
public:
	CConfigNMEABinaryOutputDestination(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigNMEABinaryOutputDestination() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

protected:
	BOOL m_nMode;
	int m_nAttribute;

	DECLARE_MESSAGE_MAP()
};

// CConfigParameterSearchEngineNumber ��ܤ��
class CConfigParameterSearchEngineNumber : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigParameterSearchEngineNumber)
public:
	CConfigParameterSearchEngineNumber(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigParameterSearchEngineNumber() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeMode();

protected:
	BOOL m_nMode;
	int m_nAttribute;

	DECLARE_MESSAGE_MAP()
};

// CConfigPositionFixNavigationMask ��ܤ��
class CConfigPositionFixNavigationMask : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigPositionFixNavigationMask)
public:
	CConfigPositionFixNavigationMask(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigPositionFixNavigationMask() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
protected:
	int m_nMask1;
	int m_nMask2;
	int m_nAttribute;

	DECLARE_MESSAGE_MAP()
};

// ConfigRefTimeToGpsTimeDlg ��ܤ��
class ConfigRefTimeToGpsTimeDlg : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(ConfigRefTimeToGpsTimeDlg)
public:
	ConfigRefTimeToGpsTimeDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~ConfigRefTimeToGpsTimeDlg() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

protected:
	BOOL m_isEnable;
	int m_nYear;
	int m_nMonth;
	int m_nDay;
	int m_nAttribute;

	DECLARE_MESSAGE_MAP()
};

// ConfigQueryGnssNavSolDlg ��ܤ��
class ConfigQueryGnssNavSolDlg : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(ConfigQueryGnssNavSolDlg)
public:
	ConfigQueryGnssNavSolDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~ConfigQueryGnssNavSolDlg() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

protected:
	U16 m_mode;
	U08 m_attribute;

	DECLARE_MESSAGE_MAP()
};

// ConfigBinaryMeasurementDataOutDlg ��ܤ��
class ConfigBinaryMeasurementDataOutDlg : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(ConfigBinaryMeasurementDataOutDlg)
public:
	ConfigBinaryMeasurementDataOutDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~ConfigBinaryMeasurementDataOutDlg() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
protected:
	U08 m_rate;
	U08 m_measTime;
	U08 m_rawMeas;
	U08 m_svChStatus;
	U08 m_rcvChStatus;
	U08 m_subFrame;
	U08 m_attribute;

	DECLARE_MESSAGE_MAP()
};

// CConfigLeapSeconds ��ܤ��
class CConfigLeapSeconds : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigLeapSeconds)
public:
	CConfigLeapSeconds(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigLeapSeconds() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

protected:
	U08 m_nLeapSeconds;
	int m_nAttribute;	
	
	DECLARE_MESSAGE_MAP()
};

// CConfigPowerMode ��ܤ��
class CConfigPowerMode : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigPowerMode)
public:
	CConfigPowerMode(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigPowerMode() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

protected:
	U16 m_nPowerMode;
	int m_nAttribute;	
	
	DECLARE_MESSAGE_MAP()
};

// CConfigParamSearchEngineSleepCRiteria ��ܤ��
class CConfigParamSearchEngineSleepCRiteria : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigParamSearchEngineSleepCRiteria)
public:
	CConfigParamSearchEngineSleepCRiteria(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigParamSearchEngineSleepCRiteria() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

protected:
	U08 m_nTrackedNumber;
	int m_nAttribute;	
	
	DECLARE_MESSAGE_MAP()
};

// CConfigDatumIndex ��ܤ��
class CConfigDatumIndex : public CCommonConfigDlg
{
	DECLARE_DYNAMIC(CConfigDatumIndex)
public:
	CConfigDatumIndex(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfigDatumIndex() {};

	virtual void DoCommand();

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

protected:
	U16 m_nDatumIndex;
	int m_nAttribute;	
	
	DECLARE_MESSAGE_MAP()
};