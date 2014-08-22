#pragma once


// CGetGNSSEphemeris ��ܤ��

class CGetGNSSEphemeris : public CDialog
{
	DECLARE_DYNAMIC(CGetGNSSEphemeris)

public:
	CGetGNSSEphemeris(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CGetGNSSEphemeris();

// ��ܤ�����
	enum { IDD = IDD_GET_GNSS_EPHEMERIS };

	CEdit m_file_gps,m_file_glonass;
	CComboBox m_sv_gps,m_sv_glonass;
	CString GPS_fileName,Glonass_fileName;

	U08 isAlmanac;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnBrowseGps();
	afx_msg void OnBnClickedBtnBrowseGlonass();
	virtual BOOL OnInitDialog();
};
