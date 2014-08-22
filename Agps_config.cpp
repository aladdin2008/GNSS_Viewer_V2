// Agps_config.cpp : ��@��
//

#include "stdafx.h"
#include "GPS.h"
#include "Agps_config.h"


// CAgps_config ��ܤ��

IMPLEMENT_DYNAMIC(CAgps_config, CDialog)
CAgps_config::CAgps_config(CWnd* pParent /*=NULL*/)
	: CDialog(CAgps_config::IDD, pParent)
{
	enable = false ;
	attribute = 0;
}

CAgps_config::~CAgps_config()
{
}

void CAgps_config::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX,IDC_COMBO_STATUS,cbo_status);
	DDX_CBIndex(pDX,IDC_AGPS_ATTR,attribute);
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAgps_config, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CAgps_config �T���B�z�`��

void CAgps_config::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	enable = cbo_status.GetCurSel();
	OnOK();
}

BOOL CAgps_config::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �b���[�J�B�~����l��
	cbo_status.SetCurSel(enable);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}

void CAgps_config::Set_Enable(U08 m_enable)
{
	enable = m_enable;
	//cbo_status.SetCurSel(enable);
}
