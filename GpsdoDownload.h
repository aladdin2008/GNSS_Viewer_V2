#pragma once


// CGpsdoDownload ��ܤ��

class CGpsdoDownload : public CDialog
{
	DECLARE_DYNAMIC(CGpsdoDownload)

public:
	CGpsdoDownload(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CGpsdoDownload();

// ��ܤ�����
	//enum { IDD = IDD_GPSDO_DOWNLOAD };
	CString m_strMasterPath;
	CString m_strSlavePath;

protected:
	void SaveSetting();
	void LoadSetting();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBrowseMaster();
	afx_msg void OnBnClickedBrowseSlave();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnBnClickedDownload();
};
