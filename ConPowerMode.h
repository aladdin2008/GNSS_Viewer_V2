#pragma once


// CConPowerMode ��ܤ��

class CConPowerMode : public CDialog
{
	DECLARE_DYNAMIC(CConPowerMode)

public:
	CConPowerMode(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConPowerMode();

	int mode;
	int attribute;
// ��ܤ�����
	enum { IDD = IDD_CON_POWERMODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
