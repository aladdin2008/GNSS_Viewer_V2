#pragma once


// CConMultiPath ��ܤ��

class CConMultiPath : public CDialog
{
	DECLARE_DYNAMIC(CConMultiPath)

public:
	CConMultiPath(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CConMultiPath();

	int multipath;
	int attribute;
// ��ܤ�����
	enum { IDD = IDD_CON_MULTIPATH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
};
