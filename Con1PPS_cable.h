#pragma once


// CCon1PPS_cable ��ܤ��

class CCon1PPS_cable : public CDialog
{
	DECLARE_DYNAMIC(CCon1PPS_cable)

public:
	CCon1PPS_cable(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CCon1PPS_cable();

// ��ܤ�����
	enum { IDD = IDD_1PPS_CABLE };

	int cable_delay;
	int attr;

	CEdit m_cable_delay;
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
};
