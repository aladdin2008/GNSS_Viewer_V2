#pragma once


// CConfig_Powersaving_param ��ܤ��

class CConfig_Powersaving_param : public CDialog
{
	DECLARE_DYNAMIC(CConfig_Powersaving_param)

public:
	CConfig_Powersaving_param(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfig_Powersaving_param();

	int param[9];
	int attr;

// ��ܤ�����
	enum { IDD = IDD_POWERSAVING_PARAM };

	void SetRomMode(bool b) { romMode = b; }
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
	bool romMode;

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
