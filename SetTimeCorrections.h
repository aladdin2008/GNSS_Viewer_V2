#pragma once


// CSetTimeCorrections ��ܤ��

class CSetTimeCorrections : public CDialog
{
	DECLARE_DYNAMIC(CSetTimeCorrections)

public:
	CSetTimeCorrections(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CSetTimeCorrections();

// ��ܤ�����
	enum { IDD = IDD_SETTIMECORR };

	CString _filename;
	int _attr;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBrowse();
	virtual BOOL OnInitDialog();
};
