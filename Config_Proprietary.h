#pragma once


// CConfig_Proprietary ��ܤ��

class CConfig_Proprietary : public CDialog
{
	DECLARE_DYNAMIC(CConfig_Proprietary)

public:
	CConfig_Proprietary(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConfig_Proprietary();

// ��ܤ�����
	enum { IDD = IDD_CON_PROPRIETARY };

	int enable;
	int attr;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
};
