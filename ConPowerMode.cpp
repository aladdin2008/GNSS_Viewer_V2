// ConPowerMode.cpp : ��@��
//

#include "stdafx.h"
#include "GPS.h"
#include "ConPowerMode.h"


// CConPowerMode ��ܤ��

IMPLEMENT_DYNAMIC(CConPowerMode, CDialog)
CConPowerMode::CConPowerMode(CWnd* pParent /*=NULL*/)
	: CDialog(CConPowerMode::IDD, pParent)
{
	mode = 0;
	attribute = 0;
}

CConPowerMode::~CConPowerMode()
{
}

void CConPowerMode::DoDataExchange(CDataExchange* pDX)
{
	DDX_CBIndex(pDX,IDC_MULTI_MODE,mode);
	DDX_CBIndex(pDX,IDC_MULTIMODE_ATTR,attribute);
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConPowerMode, CDialog)
	ON_BN_CLICKED(IDOK, &CConPowerMode::OnBnClickedOk)
END_MESSAGE_MAP()


// CConPowerMode �T���B�z�`��

void CConPowerMode::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	OnOK();
}
