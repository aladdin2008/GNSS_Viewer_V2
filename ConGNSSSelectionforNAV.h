#pragma once


// CConGNSSSelectionforNAV ��ܤ��

class CConGNSSSelectionforNAV : public CDialog
{
	DECLARE_DYNAMIC(CConGNSSSelectionforNAV)

public:
	CConGNSSSelectionforNAV(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConGNSSSelectionforNAV();

// ��ܤ�����
	enum { IDD = IDD_CON_GNSS_SELECTION };

	int selection;
	int attr;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
