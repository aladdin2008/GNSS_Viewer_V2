#pragma once


// CVerifyFwDlg ��ܤ��

class CVerifyFwDlg : public CDialog
{
	DECLARE_DYNAMIC(CVerifyFwDlg)

public:
	CVerifyFwDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CVerifyFwDlg();

// ��ܤ�����
//	enum { IDD = IDD_VERIFY_FW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
	bool AutoFill(const CString& s);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSelect();
	afx_msg void OnBnClickedGo();
};
