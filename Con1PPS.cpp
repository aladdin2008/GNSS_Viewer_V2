// Con1PPS.cpp : ��@��
//

#include "stdafx.h"
#include "GPS.h"
#include "Con1PPS.h"


// CCon1PPS ��ܤ��

IMPLEMENT_DYNAMIC(CCon1PPS, CDialog)
CCon1PPS::CCon1PPS(CWnd* pParent /*=NULL*/)
	: CDialog(CCon1PPS::IDD, pParent)
{
	_1ppsmode = _1ppsattr = 0;
}

CCon1PPS::~CCon1PPS()
{
}

void CCon1PPS::DoDataExchange(CDataExchange* pDX)
{
	DDX_CBIndex(pDX,IDC_1PPS_MODE,_1ppsmode);
	DDX_CBIndex(pDX,IDC_1PPS_ATTR,_1ppsattr);
	DDX_Control(pDX,IDC_1PPS_MODE,m_1pps);
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCon1PPS, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CCon1PPS �T���B�z�`��

BOOL CCon1PPS::OnInitDialog()
{
	CDialog::OnInitDialog();
	//Off;On when 3D fix;On when 1 SV;
	m_1pps.Clear();


	m_1pps.AddString("Not sync to UTC second");
	m_1pps.AddString("Sync to UTC second when 3D fix");

	m_1pps.SetCurSel(0);
	// TODO:  �b���[�J�B�~����l��

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}

void CCon1PPS::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	OnOK();
}
