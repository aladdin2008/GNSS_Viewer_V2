#pragma once


// CLogin ��ܤ��

class CLogin : public CDialog
{
	DECLARE_DYNAMIC(CLogin)

public:
	CLogin(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CLogin();

// ��ܤ�����
	enum { IDD = IDD_LOGIN };

	CString password;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
};
