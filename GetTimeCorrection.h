#pragma once


// CGetTimeCorrection ��ܤ��

class CGetTimeCorrection : public CDialog
{
	DECLARE_DYNAMIC(CGetTimeCorrection)

public:
	CGetTimeCorrection(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CGetTimeCorrection();

// ��ܤ�����
	enum { IDD = IDD_GETTIMECORR };

	CString _filename;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBrowse();
};
