
#pragma once


// CCon1PPS_Nmea_Delay ��ܤ��

class CCon1PPS_Nmea_Delay : public CDialog
{
	DECLARE_DYNAMIC(CCon1PPS_Nmea_Delay)

public:
	CCon1PPS_Nmea_Delay(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CCon1PPS_Nmea_Delay();

// ��ܤ�����
	enum { IDD = IDD_CON_1PPS_NMEA_DELAY };

	int nmea_delay;
	int attr;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
};
