#pragma once


// CiQibla_Test ��ܤ��

class CiQibla_Test : public CDialog
{
	DECLARE_DYNAMIC(CiQibla_Test)

public:
	CiQibla_Test(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CiQibla_Test();

	double lat,lon,timezone;
	int using_gps;

// ��ܤ�����
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedChkUsingGps();
};
