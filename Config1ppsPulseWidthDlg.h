#pragma once


// CConfig1ppsPulseWidthDlg ��ܤ��

class CConfig1ppsPulseWidthDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfig1ppsPulseWidthDlg)

public:
	CConfig1ppsPulseWidthDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfig1ppsPulseWidthDlg();

// ��ܤ�����
//	enum { IDD = IDD_CONFIG_1PPS_PULSE_WIDTH };
	UINT32 m_nPulseWidth;
	int m_nAttribute;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
