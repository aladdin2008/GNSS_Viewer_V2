#pragma once



class CConfig_Password : public CDialog
{
	DECLARE_DYNAMIC(CConfig_Password)

public:
	CConfig_Password(CWnd* pParent = NULL);
	virtual ~CConfig_Password();

	char old_password[9], new_password[9];
	CEdit m_old, m_new;

// ��ܤ�����
	enum { IDD = IDD_CONFIG_PASSWORD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);   
	afx_msg void OnBnClickedOk();

	DECLARE_MESSAGE_MAP()
};
