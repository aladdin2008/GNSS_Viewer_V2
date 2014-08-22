// ScanDlg.cpp : ��@��
//

#include "stdafx.h"
#include "GPS.h"
#include "ScanDlg.h"


extern HANDLE hScanGPS;


// CScanDlg ��ܤ��

IMPLEMENT_DYNAMIC(CScanDlg, CDialog)
CScanDlg::CScanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScanDlg::IDD, pParent)
{
}

CScanDlg::~CScanDlg()
{
}

void CScanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_EDIT2, m_msg);
}


BEGIN_MESSAGE_MAP(CScanDlg, CDialog)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
END_MESSAGE_MAP()


// CScanDlg �T���B�z�`��

BOOL CScanDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_progress.SetRange(0,100);
	m_progress.SetStep(1);
	m_progress.SetPos(0);
	m_msg.SetWindowText("Start to Scan GPS");
	Pos = 0;	
	IsFinish = false;
	if(!SetEvent(hScanGPS))	DWORD error = GetLastError();
	
	SetTimer(1,0,NULL);
	// TODO:  �b���[�J�B�~����l��

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}


void CScanDlg::OnTimer(UINT nIDEvent)
{

	Pos+=10;
	if(Pos == 100)
		Pos = 0;
	m_progress.SetPos(Pos);
	if(IsFinish)
	{
		KillTimer(1);
		OnOK();
	}

	
	

	CDialog::OnTimer(nIDEvent);
}

void CScanDlg::OnBnClickedButton1()
{
	IsFinish = TRUE;
	OnOK();
}
