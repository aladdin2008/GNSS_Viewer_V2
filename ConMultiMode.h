#pragma once


// CConMultiMode ��ܤ��

class CConMultiMode : public CDialog
{
	DECLARE_DYNAMIC(CConMultiMode)

public:
	CConMultiMode(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConMultiMode();

// ��ܤ�����
	enum { IDD = IDD_CON_MULTI_MODE };
	
	int mode;
	int attribute;

	CComboBox m_mode;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCustom();
	afx_msg void OnBnClickedBuildIn();
};
