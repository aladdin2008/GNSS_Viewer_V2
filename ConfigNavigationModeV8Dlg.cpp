// ConfigSAGPS.cpp : ��@��
//
#include "stdafx.h"
#include "Resource.h"
#include "ConfigNavigationModeV8Dlg.h"

// ConfigNavigationModeV8Dlg ��ܤ��
IMPLEMENT_DYNAMIC(ConfigNavigationModeV8Dlg, CDialog)

ConfigNavigationModeV8Dlg::ConfigNavigationModeV8Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CONFIG_SAGPS, pParent)
{
	m_nMode = 0;
	m_nAttribute = 0;
}

ConfigNavigationModeV8Dlg::~ConfigNavigationModeV8Dlg()
{
}

void ConfigNavigationModeV8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ConfigNavigationModeV8Dlg, CDialog)
	ON_BN_CLICKED(IDOK, &ConfigNavigationModeV8Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ConfigNavigationModeV8Dlg �T���B�z�`��
void ConfigNavigationModeV8Dlg::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	CString txt;

	m_nMode = ((CComboBox*)GetDlgItem(IDC_MODE))->GetCurSel();
	m_nAttribute = ((CComboBox*)GetDlgItem(IDC_BINARY_ATTRI))->GetCurSel();;

	OnOK();
}

BOOL ConfigNavigationModeV8Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �b���[�J�B�~����l��
	((CComboBox*)GetDlgItem(IDC_MODE))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_BINARY_ATTRI))->SetCurSel(0);;

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}
