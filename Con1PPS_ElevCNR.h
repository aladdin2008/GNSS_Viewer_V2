#pragma once


// CCon1PPS_ElevCNR ��ܤ��

class CCon1PPS_ElevCNR : public CDialog
{
	DECLARE_DYNAMIC(CCon1PPS_ElevCNR)

public:
	CCon1PPS_ElevCNR(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CCon1PPS_ElevCNR();

// ��ܤ�����
	enum { IDD = IDD_1PPS_ELEVCNR };

	CButton m_bboth,m_belev,m_bcnr,m_disable;

	CEdit m_elev,m_cnr;

	CComboBox m_attr;

	int sel,elev,cnr,attr;


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadioElevAndCnr();
	afx_msg void OnBnClickedRadioElev();
	afx_msg void OnBnClickedRadioCnr();
	afx_msg void OnBnClickedRadioElevDiable();
};
