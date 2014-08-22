#pragma once

#include "stdafx.h"

//#include <list>
//using std::list;

// CFTPDlg ��ܤ��

class CFTPDlg : public CDialog
{
	DECLARE_DYNAMIC(CFTPDlg)

public:
	CFTPDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CFTPDlg();

// ��ܤ�����
	enum { IDD = IDD_FTPDLG };

	virtual BOOL OnInitDialog();

	void GetAgpsFile();
	void SetMode(int m);


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
	virtual void OnCancel();

	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedClose();

	bool GetFtpFile();
	void FindEphemerisFile();
	void DownloadFileFromFTP(CString& ,CFtpConnection* );
	void GetAllDatFileSrec();
	void DoRomAgps();
	bool UploadSrec();
	bool UploadBin();
	bool TransferFile(BinaryData& ephData);

private:
//	HANDLE  m_hClose;

	CButton m_closeBtn;
	CButton m_connectBtn;

	CProgressCtrl m_progress;
	int m_agpsMode;		//0=normal,1=srec type
	CEdit m_host;
	CEdit m_name;
	CEdit m_pwd;
	CEdit m_port;
	CEdit m_text;
	CStatic m_ftp_title;
	CString m_ephFileName;

//	CString filepath;
//	CString sPath;
//	CString FileName[50];	
//	void GetAllDatFile();
//	int num;
//	int NoOfFile ;
//	int NumOfFile;
//	bool pressclose;
//	bool clickOK;
//	bool upload_error;



	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedErase();
	afx_msg void OnStnClickedNameT();
};
