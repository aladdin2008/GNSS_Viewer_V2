#pragma once


// DrMultiHzDlg ��ܤ��

class DrMultiHzDlg : public CDialog
{
	DECLARE_DYNAMIC(DrMultiHzDlg)

public:
	DrMultiHzDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~DrMultiHzDlg();

// ��ܤ�����
//	enum { IDD = IDD_CONFIG_DRUPDATERATE };
	
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
