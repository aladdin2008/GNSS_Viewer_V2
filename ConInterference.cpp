// ConInterference.cpp : ��@��
//

#include "stdafx.h"
#include "GPS.h"
#include "ConInterference.h"


// CConInterference ��ܤ��

IMPLEMENT_DYNAMIC(CConInterference, CDialog)

CConInterference::CConInterference(CWnd* pParent /*=NULL*/)
	: CDialog(CConInterference::IDD, pParent)
{
	mode = 0;
}

CConInterference::~CConInterference()
{
}

void CConInterference::DoDataExchange(CDataExchange* pDX)
{

	DDX_CBIndex(pDX,IDC_INTERFERENCE_MODE,mode);
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConInterference, CDialog)
END_MESSAGE_MAP()


// CConInterference �T���B�z�`��

BOOL CConInterference::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �b���[�J�B�~����l��

	//UpdateData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}
