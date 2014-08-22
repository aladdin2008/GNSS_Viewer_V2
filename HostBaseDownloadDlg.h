#pragma once


// CHostBaseDownloadDlg ��ܤ��

class CHostBaseDownloadDlg : public CDialog
{
	DECLARE_DYNAMIC(CHostBaseDownloadDlg)

public:
	CHostBaseDownloadDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CHostBaseDownloadDlg();

// ��ܤ�����
//	enum { IDD = IDD_HOSTBASE_DL };
	virtual BOOL OnInitDialog();

	int GetBaudrateIndex() { return m_nBaudrateIdx; };
	CString GetFilePath() { return m_strPath; };

	int GetBufferIndex() { return m_nBufferIdx; };

protected:
	int m_nBaudrateIdx;
	CString m_strPath;
	int m_nBufferIdx;

	void GetValue();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
	virtual void OnOK();

	afx_msg void OnClose();
	afx_msg void OnBnClickedBrowse();
	afx_msg void OnBnClickedSendCmd();
	afx_msg void OnBnClickedSendBin();

	DECLARE_MESSAGE_MAP()

};
