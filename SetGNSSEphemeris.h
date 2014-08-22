#pragma once


// CSetGNSSEphemeris ��ܤ��

class CSetGNSSEphemeris : public CDialog
{
	DECLARE_DYNAMIC(CSetGNSSEphemeris)

public:
	CSetGNSSEphemeris(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CSetGNSSEphemeris();

// ��ܤ�����
	enum { IDD = IDD_SET_GNSS_EPHEMERIS };

	CEdit m_file_gps,m_file_glonass;
	CString GPS_fileName,Glonass_fileName;

	U08 isAlmanac;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnBrowseGps();
	afx_msg void OnBnClickedBtnBrowseGlonass();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
