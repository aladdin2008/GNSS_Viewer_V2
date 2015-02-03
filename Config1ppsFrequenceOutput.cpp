// Config1ppsFrequenceOutput.cpp : ��@��
//

#include "stdafx.h"
#include "Resource.h"
#include "Config1ppsFrequenceOutput.h"


// CConfig1ppsFrequenceOutput ��ܤ��

IMPLEMENT_DYNAMIC(CConfig1ppsFrequenceOutput, CDialog)

CConfig1ppsFrequenceOutput::CConfig1ppsFrequenceOutput(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CONFIG_1PPS_FREQ_OUTPUT, pParent)
{

	EnableAutomation();

}

CConfig1ppsFrequenceOutput::~CConfig1ppsFrequenceOutput()
{
}

void CConfig1ppsFrequenceOutput::OnFinalRelease()
{
	// ������ Automation ����̫᪺�ѦҮɡA
	// �|�I�s OnFinalRelease�C�����O�|�۰�
	// �R������C�I�s�����O�e�A�Х��[�J�z����һݪ��B�~�M�� (Cleanup)
	// �{���X�C

	CDialog::OnFinalRelease();
}

void CConfig1ppsFrequenceOutput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConfig1ppsFrequenceOutput, CDialog)
	ON_BN_CLICKED(IDOK, &CConfig1ppsFrequenceOutput::OnBnClickedOk)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CConfig1ppsFrequenceOutput, CDialog)
END_DISPATCH_MAP()

// �`�N: �ڭ̥[�J�F�� IID_IConfig1ppsFrequenceOutput ���䴩
// �H�K�q VBA �䴩���O�w��ô���C�� IID �����P .IDL �ɤ��A
// ���[�ܤ��t���� (Dispinterface) �� GUID �۲šC

// {D1A372EB-FC2B-4847-AE3B-31031DB44A83}
static const IID IID_IConfig1ppsFrequenceOutput =
{ 0xD1A372EB, 0xFC2B, 0x4847, { 0xAE, 0x3B, 0x31, 0x3, 0x1D, 0xB4, 0x4A, 0x83 } };

BEGIN_INTERFACE_MAP(CConfig1ppsFrequenceOutput, CDialog)
	INTERFACE_PART(CConfig1ppsFrequenceOutput, IID_IConfig1ppsFrequenceOutput, Dispatch)
END_INTERFACE_MAP()


// CConfig1ppsFrequenceOutput �T���B�z�`��

BOOL CConfig1ppsFrequenceOutput::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �b���[�J�B�~����l��
	GetDlgItem(IDC_OUTPUT)->SetWindowText("10000000");
	((CComboBox*)GetDlgItem(IDC_ATTR))->SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}

void CConfig1ppsFrequenceOutput::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	CString strValue;
	GetDlgItem(IDC_OUTPUT)->GetWindowText(strValue);
	int n = atoi(strValue);
	if(n < 1 || n > 19200000)
	{
		::AfxMessageBox("Frequency must be between 1 and 19200000.");
		return;
	}
	freqOutput = n;
	freqOutputAttr = ((CComboBox*)GetDlgItem(IDC_ATTR))->GetCurSel();

	OnOK();
}
