#pragma once


// CCon_NMEA_TalkerID ��ܤ��

class CCon_NMEA_TalkerID : public CDialog
{
	DECLARE_DYNAMIC(CCon_NMEA_TalkerID)

public:
	CCon_NMEA_TalkerID(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CCon_NMEA_TalkerID();

// ��ܤ�����
	enum { IDD = IDD_CON_NMEA_TALKER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	int talkerid;
	int attr;
};
