#pragma once


// CConPosPinning ��ܤ��

class CConPosPinning : public CDialog
{
	DECLARE_DYNAMIC(CConPosPinning)

public:
	CConPosPinning(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConPosPinning();

// ��ܤ�����
	enum { IDD = IDD_CON_POSITION_PINNING };

	int m_position_pinning;
	int m_attributes;

	CComboBox position_pinning;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
