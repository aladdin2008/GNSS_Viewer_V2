#pragma once


// CGetAlmanac ��ܤ��

class CGetAlmanac : public CDialog
{
	DECLARE_DYNAMIC(CGetAlmanac)

public:
	CGetAlmanac(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CGetAlmanac();

// ��ܤ�����
	enum { IDD = IDD_GETALMANAC };

	CEdit m_filename;
	CComboBox m_sv;
	CString fileName;
	int sv;
	U08 isGlonass;
	U08 isDecode;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAlmanacBrowse();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
