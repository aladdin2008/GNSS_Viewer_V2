#pragma once


// CConPinningParameter ��ܤ��

class CConPinningParameter : public CDialog
{
	DECLARE_DYNAMIC(CConPinningParameter)

public:
	CConPinningParameter(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConPinningParameter();

// ��ܤ�����
	enum { IDD = IDD_CON_PINNING };


	int pin_speed;
	int pin_cnt;
	int upin_speed;
	int upin_threshold;
	int upin_distance;
	int attr;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
