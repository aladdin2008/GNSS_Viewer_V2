#pragma once


// CCon_binary_msg_interval ��ܤ��

class CCon_binary_msg_interval : public CDialog
{
	DECLARE_DYNAMIC(CCon_binary_msg_interval)

public:
	CCon_binary_msg_interval(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CCon_binary_msg_interval();

// ��ܤ�����
	enum { IDD = IDD_CON_USERDEFINEMSG_INTERVAL };

public:
	CSliderCtrl m_sliderctrl;
	CEdit m_val;
	CSpinButtonCtrl m_spin;
	CComboBox m_cbo;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedOk();
};
