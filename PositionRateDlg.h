#pragma once


// CPositionRateDlg ��ܤ��

class CPositionRateDlg : public CDialog
{
	DECLARE_DYNAMIC(CPositionRateDlg)

public:
	CPositionRateDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CPositionRateDlg();

// ��ܤ�����
	enum { IDD = IDD_CONFIG_POSITIONRATE };
	
	int rate;
	int attr;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
	
	CComboBox cbo_rate;
	CComboBox cbo_attr;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
