// ConMultiPath.cpp : ��@��
//

#include "stdafx.h"
#include "GPS.h"
#include "ConMultiPath.h"


// CConMultiPath ��ܤ��

IMPLEMENT_DYNAMIC(CConMultiPath, CDialog)
CConMultiPath::CConMultiPath(CWnd* pParent /*=NULL*/)
	: CDialog(CConMultiPath::IDD, pParent)
{
	multipath = 0;
	attribute = 0;
}

CConMultiPath::~CConMultiPath()
{
}

void CConMultiPath::DoDataExchange(CDataExchange* pDX)
{
	DDX_CBIndex(pDX,IDC_MULTI_PATH,multipath);
	DDX_CBIndex(pDX,IDC_MULTIPATH_ATTR,attribute);
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConMultiPath, CDialog)
END_MESSAGE_MAP()


// CConMultiPath �T���B�z�`��
