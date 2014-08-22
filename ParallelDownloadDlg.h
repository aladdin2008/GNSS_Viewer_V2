#pragma once


// CParallelDownloadDlg ��ܤ��

class CParallelDownloadDlg : public CDialog
{
	DECLARE_DYNAMIC(CParallelDownloadDlg)

public:
	CParallelDownloadDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CParallelDownloadDlg();

// ��ܤ�����
//	enum { IDD = IDD_FIRMWARE_DL };
	virtual BOOL OnInitDialog();

	int GetBaudrateIndex() { return m_nBaudrateIdx; };
	int GetFlashType() { return m_nFlashType; };
	CString GetFilePath() { return m_strPath; };
	//BOOL IsInternal() { return m_isInternal; };
	//int GetBufferIndex() { return m_nBufferIdx; };

protected:
	int m_nBaudrateIdx;
	int m_nFlashType;
	CString m_strPath;
	//BOOL m_isInternal;
	//int m_nBufferIdx;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
	virtual void OnOK();

	afx_msg void OnBnClickedBrowse();


	DECLARE_MESSAGE_MAP()

};
