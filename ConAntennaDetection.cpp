// ConAntennaDetection.cpp : ��@��
//

#include "stdafx.h"
#include "GPS.h"
#include "ConAntennaDetection.h"


// CConAntennaDetection ��ܤ��

IMPLEMENT_DYNAMIC(CConAntennaDetection, CDialog)

CConAntennaDetection::CConAntennaDetection(CWnd* pParent /*=NULL*/)
	: CDialog(CConAntennaDetection::IDD, pParent)
{
	attr = 0 ;
	antenna_control = 0;
}

CConAntennaDetection::~CConAntennaDetection()
{
}

void CConAntennaDetection::DoDataExchange(CDataExchange* pDX)
{
	DDX_CBIndex(pDX,IDC_ANTENNA_DETECT_ATTR,attr);
	DDX_Control(pDX,IDC_DETECT_SHORT,m_chk_short);
	DDX_Control(pDX,IDC_DETECT_ANTENNA,m_chk_antenna);
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConAntennaDetection, CDialog)
	ON_BN_CLICKED(IDOK, &CConAntennaDetection::OnBnClickedOk)
END_MESSAGE_MAP()


// CConAntennaDetection �T���B�z�`��

BOOL CConAntennaDetection::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �b���[�J�B�~����l��

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}

void CConAntennaDetection::OnBnClickedOk()
{
	if (m_chk_short.GetCheck() == 1)
		antenna_control |= 0x01;
	if (m_chk_antenna.GetCheck() == 1)
		antenna_control |= 0x02;
	OnOK();
}
