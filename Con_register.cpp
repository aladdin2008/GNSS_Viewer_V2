// Con_register.cpp 
//

#include "stdafx.h"
#include "GPS.h"
#include "Con_register.h"


// CCon_register 

IMPLEMENT_DYNAMIC(CCon_register, CDialog)
CCon_register::CCon_register(CWnd* pParent /*=NULL*/)
	: CDialog(CCon_register::IDD, pParent)
{
  specialFunction = 0;
}

CCon_register::~CCon_register()
{
}

void CCon_register::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX,IDC_REG_ADDR,m_txt_addr);
	DDX_Control(pDX,IDC_REG_DATA,m_txt_data);

	DDX_Text(pDX,IDC_REG_ADDR,m_addr);
	DDX_Text(pDX,IDC_REG_DATA,m_data);
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCon_register, CDialog)
	ON_EN_UPDATE(IDC_REG_ADDR, OnEnUpdateRegAddr)
END_MESSAGE_MAP()


// CCon_register 

BOOL CCon_register::OnInitDialog()
{
	CString tmp;

	CDialog::OnInitDialog();

	m_txt_addr.SetLimitText(8);
	m_txt_data.SetLimitText(8);
	if(specialFunction == 1)
  {
    m_txt_addr.ShowWindow(SW_HIDE);
    GetDlgItem(IDC_STATIC_ADDR)->ShowWindow(SW_HIDE);
    SetWindowText("Set Default Clock Offset");
    GetDlgItem(IDC_STATIC_DATA)->SetWindowText("Clock Offset 0X");
  }
	return TRUE;  // return TRUE unless you set the focus to a control
}

void CCon_register::OnEnUpdateRegAddr()
{
	//CString tmp;
	//m_txt_addr.GetWindowText(tmp);
	//if (tmp.GetLength() > 8)
	//	tmp = tmp.Left(8);
	//m_txt_addr.SetWindowText(tmp);
	//m_txt_addr.SetLimitText
}	
