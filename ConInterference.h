#pragma once


// CConInterference ��ܤ��

class CConInterference : public CDialog
{
	DECLARE_DYNAMIC(CConInterference)

public:
	CConInterference(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConInterference();

// ��ܤ�����
	enum { IDD = IDD_CON_INTERFERENCE };


	int mode;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
