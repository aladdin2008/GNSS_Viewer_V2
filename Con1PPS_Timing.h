#pragma once

#include "GPSDlg.h"

// CCon1PPS_Timing ��ܤ��

class CCon1PPS_Timing : public CDialog
{
	DECLARE_DYNAMIC(CCon1PPS_Timing)

public:
	CCon1PPS_Timing(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CCon1PPS_Timing();

// ��ܤ�����
	enum { IDD = IDD_1PPS_CONFIG };

	CComboBox m_combo_mode,m_attri;
	CStatic m_lbl_set1,m_lbl_set2,m_lbl_set3,m_lbl_set4;
	CEdit m_set1,m_set2,m_set3,m_set4;

	_1PPS_Timing_T _1pps_timing;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchange1ppsMode();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
