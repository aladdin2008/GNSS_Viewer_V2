#pragma once


// BinaryChecksumCalDlg ��ܤ��
class BinaryData;

class BinaryChecksumCalDlg : public CDialog
{
	DECLARE_DYNAMIC(BinaryChecksumCalDlg)

public:
	BinaryChecksumCalDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~BinaryChecksumCalDlg();

	int FindNextNoneSpaceChar(LPCSTR pszInput, bool forward = true);
	bool ConvertHexToBinary(LPCSTR pszInput, BinaryData& binData);
// ��ܤ�����
//	enum { IDD = IDD_BIN_CHECKSUM_CAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeInput();
protected:
	virtual void OnOK();

public:
	afx_msg void OnBnClickedSend();
};
