// ConSrePorDlg.cpp : ��@��
//

#include "stdafx.h"
#include "GPS.h"
#include "GPSDlg.h"
#include "ConSrePorDlg.h"
#include "Serial.h"

CConSrePorDlg* pCSPDlg;
U08 comport;
U08 baudrate;

UINT CigSrePorThread(LPVOID pParam)
{   

	U08 messages[11];    
    U08 i;	  
	memset(messages, 0, 11);
	messages[0]=(U08)0xa0;
	messages[1]=(U08)0xa1;
	messages[2]=0;
	messages[3]=4;
	messages[4]=5; //msgid		
	messages[5]=comport; 
	messages[6]=baudrate; 
	messages[7]=attribute;
    U08 checksum = 0;
	for(i=0;i<(int)messages[3];i++)	checksum^=messages[i+4];	
	messages[8]=checksum;
	messages[9]=(U08)0x0d;
	messages[10]=(U08)0x0a;	
	//for(int i=0;i<10;i++)	_cprintf("%x ",messages[i]);
	bool b = CGPSDlg::gpsDlg->SendToTarget(messages, 11, "Configure Serial Port Successful...");	
	if(b)
	{
		CGPSDlg::gpsDlg->SetBaudrate(baudrate);	
	}
//	CP->Nmeamessage();
	CGPSDlg::gpsDlg->SetMode();	
	CGPSDlg::gpsDlg->CreateGPSThread();	
	CGPSDlg::gpsDlg->WriteIni();
//	AfxEndThread(0);
	return 0;
}

// CConSrePorDlg ��ܤ��

IMPLEMENT_DYNAMIC(CConSrePorDlg, CDialog)
CConSrePorDlg::CConSrePorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConSrePorDlg::IDD, pParent)
{
}

CConSrePorDlg::~CConSrePorDlg()
{
}

void CConSrePorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CON_COMPORT, m_comport);
	DDX_Control(pDX, IDC_CON_BAUD, m_baudrate);	
	DDX_Control(pDX, IDC_CON_BAUD2, m_attribute);
}


BEGIN_MESSAGE_MAP(CConSrePorDlg, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CConSrePorDlg �T���B�z�`��

BOOL CConSrePorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	pCSPDlg=this;
	m_comport.SetCurSel(0);
	if(_V8_SUPPORT)
	{
		m_baudrate.ResetContent();
		for(int i=0; i<9; ++i)
		{
			CString strIdx;
			strIdx.Format("%d", CSerial::BaudrateTable[i]);
			m_baudrate.AddString(strIdx);
		}
	}
	else
	{
		m_baudrate.ResetContent();
		for(int i=0; i<6; ++i)
		{
			CString strIdx;
			strIdx.Format("%d", CSerial::BaudrateTable[i]);
			m_baudrate.AddString(strIdx);
		}
	}
	if(!IS_DEBUG)
	{
		GetDlgItem(IDC_CON_COMPORT_T)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CON_COMPORT)->ShowWindow(SW_HIDE);
	}

	m_baudrate.SetCurSel(5);
	m_attribute.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}

void CConSrePorDlg::OnBnClickedOk()
{
	comport  = m_comport.GetCurSel();
	baudrate = m_baudrate.GetCurSel();
	attribute= m_attribute.GetCurSel();
	AfxBeginThread(CigSrePorThread,0);	
	OnOK();
}



