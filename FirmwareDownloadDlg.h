#pragma once


// CFirmwareDownloadDlg ��ܤ��

class CFirmwareDownloadDlg : public CDialog
{
	DECLARE_DYNAMIC(CFirmwareDownloadDlg)

public:
	CFirmwareDownloadDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CFirmwareDownloadDlg();

// ��ܤ�����
//	enum { IDD = IDD_FIRMWARE_DL };
	virtual BOOL OnInitDialog();

public:
	enum LoaderType {
		UsingExternalLoader = 0,
		V6GpsSeriesLoader,
		V6GnssSeriesLoader,
		V6Gg12aLoader,
		V8SerialLoader,
		UsingExternalLoaderInBinCmd,
		OLinkStarDownload,
	};

	LoaderType GetLoaderType() { return m_nLoaderType; };
	int GetBaudrateIndex() { return m_nBaudrateIdx; };
	CString GetFilePath() { return m_strPath; };
	BOOL IsInternal() { return m_isInternal; };
	int GetBufferIndex() { return m_nBufferIdx; };

protected:
	LoaderType m_nLoaderType;
	int m_nBaudrateIdx;
	CString m_strPath;
	BOOL m_isInternal;
	int m_nBufferIdx;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
	virtual void OnOK();

	afx_msg void OnBnClickedBrowse();


	DECLARE_MESSAGE_MAP()

};
