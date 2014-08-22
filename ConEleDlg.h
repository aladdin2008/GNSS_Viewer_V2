#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CConEleDlg ��ܤ��

class CConEleDlg : public CDialog
{
	DECLARE_DYNAMIC(CConEleDlg)

public:
	CConEleDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConEleDlg();

// ��ܤ�����
	enum { IDD = IDD_CFG_ELE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_eele;
	CSpinButtonCtrl m_spele;
	CSliderCtrl m_slele;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedOk();
};
