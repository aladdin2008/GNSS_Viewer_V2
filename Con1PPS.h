#pragma once


// CCon1PPS ��ܤ��

class CCon1PPS : public CDialog
{
	DECLARE_DYNAMIC(CCon1PPS)

public:
	CCon1PPS(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CCon1PPS();

// ��ܤ�����
	enum { IDD = IDD_CON_1PPS };
	
	CComboBox m_1pps;
	int _1ppsmode;
	int _1ppsattr;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
