#pragma once

#include "resource.h"

// CExternalSrecDlg ��ܤ��

class CExternalSrecDlg : public CDialog
{
	DECLARE_DYNAMIC(CExternalSrecDlg)

public:
	CExternalSrecDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CExternalSrecDlg();
	void AddMsgToList(LPCTSTR msg);

// ��ܤ�����
	enum { IDD = IDD_EXTERNAL_SREC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
	bool DownloadLoader(CString externalSrecFile);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBrowse();
	afx_msg void OnBnClickedGo();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnDestroy();
protected:
	virtual void OnOK();
  bool m_isV6;
};
