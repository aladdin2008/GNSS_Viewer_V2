// iQibla_Test.cpp : ��@��
//

#include "stdafx.h"
#include "GPS.h"
#include "iQibla_Test.h"


// CiQibla_Test ��ܤ��

IMPLEMENT_DYNAMIC(CiQibla_Test, CDialog)

CiQibla_Test::CiQibla_Test(CWnd* pParent /*=NULL*/)
	: CDialog(CiQibla_Test::IDD, pParent)
{
	using_gps = 0;
	lat = lon = timezone = 0;
}

CiQibla_Test::~CiQibla_Test()
{
}

void CiQibla_Test::DoDataExchange(CDataExchange* pDX)
{
	DDX_Check(pDX,IDC_CHK_USING_GPS,using_gps);
	DDX_Text(pDX,IDC_IQIBLA_LAT,lat);
	DDX_Text(pDX,IDC_IQIBLA_LON,lon);
	DDX_Text(pDX,IDC_IQIBLA_TIMEZONE,timezone);

	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CiQibla_Test, CDialog)
	ON_BN_CLICKED(IDOK, &CiQibla_Test::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHK_USING_GPS, &CiQibla_Test::OnBnClickedChkUsingGps)
END_MESSAGE_MAP()


// CiQibla_Test �T���B�z�`��

void CiQibla_Test::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	OnOK();
}

void CiQibla_Test::OnBnClickedChkUsingGps()
{
	
}
