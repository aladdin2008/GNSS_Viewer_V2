#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CConDOPDlg ��ܤ��

class CConDOPDlg : public CDialog
{
	DECLARE_DYNAMIC(CConDOPDlg)

public:
	CConDOPDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConDOPDlg();

// ��ܤ�����
	enum { IDD = IDD_CON_DOP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
	virtual void PreInitDialog();
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CComboBox m_dopsel;
	CEdit m_egdop;
	CEdit m_epdop;
	CEdit m_ehdop;
	CSpinButtonCtrl m_spgdop;
	CSpinButtonCtrl m_sppdop;
	CSpinButtonCtrl m_sphdop;
	CSliderCtrl m_slgdop;
	CSliderCtrl m_slpdop;
	CSliderCtrl m_slhdop;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
