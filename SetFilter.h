#pragma once


// CSetFilter ��ܤ��

class CSetFilter : public CDialog
{
	DECLARE_DYNAMIC(CSetFilter)

public:
	CSetFilter(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CSetFilter();

// ��ܤ�����
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
};
