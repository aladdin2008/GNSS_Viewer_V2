#pragma once


// CPositionFinderDlg ��ܤ��

class CPositionFinderDlg : public CDialog
{
	DECLARE_DYNCREATE(CPositionFinderDlg)

public:
	CPositionFinderDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CPositionFinderDlg();

// ��ܤ�����
	enum { IDD = IDD_CONFIG_POSSET};

	D64 lat;
	D64 lon;
	int unit_sel;
	int attr;

	CEdit m_lat,m_lon;


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
