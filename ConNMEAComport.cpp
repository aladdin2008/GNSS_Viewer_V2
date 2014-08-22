// ConNMEAComport.cpp : ��@��
//

#include "stdafx.h"
#include "GPS.h"
#include "ConNMEAComport.h"


// CConNMEAComport ��ܤ��

IMPLEMENT_DYNAMIC(CConNMEAComport, CDialog)

CConNMEAComport::CConNMEAComport(CWnd* pParent /*=NULL*/)
	: CDialog(CConNMEAComport::IDD, pParent)
	, attr(0)
{
	comport = 1;
}

CConNMEAComport::~CConNMEAComport()
{
}

void CConNMEAComport::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHK_NMEA_COM0, m_com0);
	DDX_Control(pDX, IDC_CHK_NMEA_COM1, m_com1);
	DDX_CBIndex(pDX, IDC_NMEA_COM_ATTR, attr);
	DDV_MinMaxInt(pDX, attr, 0, 1);
}


BEGIN_MESSAGE_MAP(CConNMEAComport, CDialog)
	ON_BN_CLICKED(IDOK, &CConNMEAComport::OnBnClickedOk)
END_MESSAGE_MAP()


// CConNMEAComport �T���B�z�`��

BOOL CConNMEAComport::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �b���[�J�B�~����l��
	m_com0.SetCheck(0);
	m_com1.SetCheck(0);



	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}

void CConNMEAComport::OnBnClickedOk()
{
	comport = 0;
	if (m_com0.GetCheck())
		comport |= 0x01;
	if (m_com1.GetCheck())
		comport |= 0x02;
	// TODO: �b���[�J����i���B�z�`���{���X
	OnOK();
}
