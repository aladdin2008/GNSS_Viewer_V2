#pragma once


// NmeaChecksumCalDlg ��ܤ��

class NmeaChecksumCalDlg : public CDialog
{
	DECLARE_DYNAMIC(NmeaChecksumCalDlg)

public:
	NmeaChecksumCalDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~NmeaChecksumCalDlg();

// ��ܤ�����
//	enum { IDD = IDD_NMEA_CHECKSUM_CAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeInput();

protected:
	CString GetFullNmeaString(const CString& s);

public:
	afx_msg void OnBnClickedSend();
};
