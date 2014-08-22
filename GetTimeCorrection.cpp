// GetTimeCorrection.cpp : ��@��
//

#include "stdafx.h"
#include "GPS.h"
#include "GetTimeCorrection.h"


// CGetTimeCorrection ��ܤ��

IMPLEMENT_DYNAMIC(CGetTimeCorrection, CDialog)

CGetTimeCorrection::CGetTimeCorrection(CWnd* pParent /*=NULL*/)
	: CDialog(CGetTimeCorrection::IDD, pParent)
{

}

CGetTimeCorrection::~CGetTimeCorrection()
{
}

void CGetTimeCorrection::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX,IDC_FILE,_filename);

	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGetTimeCorrection, CDialog)
	ON_BN_CLICKED(IDC_BROWSE, &CGetTimeCorrection::OnBnClickedBrowse)
END_MESSAGE_MAP()


// CGetTimeCorrection �T���B�z�`��

void CGetTimeCorrection::OnBnClickedBrowse()
{
	CFileDialog dlgFile(false, _T("log"), "GlonassTimeCorrections.log", OFN_HIDEREADONLY, _T("ALL Files (*.*)|*.*||"), this);
	if(dlgFile.DoModal() == IDOK)
	{
		_filename = dlgFile.GetPathName();

		UpdateData(FALSE);
	}
}
