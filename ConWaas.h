#pragma once


// CConWaas ��ܤ��

class CConWaas : public CDialog
{
	DECLARE_DYNAMIC(CConWaas)

public:
	CConWaas(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConWaas();
	int waas;
	int attribute;
// ��ܤ�����
	enum { IDD = IDD_CON_WAAS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
