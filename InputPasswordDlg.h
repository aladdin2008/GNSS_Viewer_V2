#pragma once

// CInputPassword ��ܤ��
class CInputPassword : public CDialog
{
	DECLARE_DYNAMIC(CInputPassword)

public:
	CInputPassword(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CInputPassword();

// ��ܤ�����
//	enum { IDD = IDD_PASSWD };
	CString GetPassword() { return password; };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()

	CString password;

public:
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
};
