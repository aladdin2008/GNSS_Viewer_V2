#pragma once


// CProprietary_nmea ��ܤ��

class CProprietary_nmea : public CDialog
{
	DECLARE_DYNAMIC(CProprietary_nmea)

public:
	CProprietary_nmea(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CProprietary_nmea();

// ��ܤ�����
	enum { IDD = IDD_PROPRIETARY_NMEA };

	CComboBox m_psti_id;
	CComboBox m_psti,m_attr;

	int psti_id, psti_interval, attr;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
