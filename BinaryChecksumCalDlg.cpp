// BinaryChecksumCalDlg.cpp : ��@��
//

#include "stdafx.h"
#include "BinaryChecksumCalDlg.h"
#include "Resource.h"
#include "GPSDlg.h"
#include "Serial.h"


// BinaryChecksumCalDlg ��ܤ��

IMPLEMENT_DYNAMIC(BinaryChecksumCalDlg, CDialog)

BinaryChecksumCalDlg::BinaryChecksumCalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_BIN_CHECKSUM_CAL, pParent)
{

}

BinaryChecksumCalDlg::~BinaryChecksumCalDlg()
{
}

void BinaryChecksumCalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BinaryChecksumCalDlg, CDialog)
	ON_EN_CHANGE(IDC_CONTEXT, &BinaryChecksumCalDlg::OnEnChangeInput)
	ON_BN_CLICKED(IDC_SEND, &BinaryChecksumCalDlg::OnBnClickedSend)
END_MESSAGE_MAP()


// BinaryChecksumCalDlg �T���B�z�`��

BOOL BinaryChecksumCalDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �b���[�J�B�~����l��
	//IDC_CHECKSUM, IDC_CONTEXT, IDC_BIN_SIZE
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX �ݩʭ����Ǧ^ FALSE
}

void BinaryChecksumCalDlg::OnOK()
{
	// TODO: �b���[�J�S�w���{���X�M (��) �I�s�����O

	CDialog::OnOK();
}

void BinaryChecksumCalDlg::OnEnChangeInput()
{
	// TODO:  �p�G�o�O RICHEDIT ����A����N���|
	// �ǰe���i���A���D�z�мg CDialog::OnInitDialog()
	// �禡�M�I�s CRichEditCtrl().SetEventMask()
	// ���㦳 ENM_CHANGE �X�� ORed �[�J�B�n�C
 	CString strInput;
	GetDlgItem(IDC_CONTEXT)->GetWindowText(strInput);

	//GetDlgItem(IDC_CHECKSUM)->SetWindowText(strInput + "_");
	BinaryData binData;
	if(!Utility::ConvertHexToBinary(strInput, binData))
	{
		GetDlgItem(IDC_BIN_SIZE)->SetWindowText("Invalidate Format!");
		GetDlgItem(IDC_CHECKSUM)->SetWindowText("Invalidate Format!");
		return;
	}

	U08 checkSum = 0;
	for(int i=0; i<binData.Size(); ++i)
	{
		checkSum ^= binData[i];
	}

	CString strOutput;
	strOutput.Format("%02X %02X", HIBYTE(binData.Size()), LOBYTE(binData.Size()));
	GetDlgItem(IDC_BIN_SIZE)->SetWindowText(strOutput);
	strOutput.Format("%02X", checkSum);
	GetDlgItem(IDC_CHECKSUM)->SetWindowText(strOutput);
}



void BinaryChecksumCalDlg::OnBnClickedSend()
{
	// TODO: �b���[�J����i���B�z�`���{���X
	if(!CGPSDlg::gpsDlg->m_isConnectOn)
	{
		AfxMessageBox("Please connect to GNSS device");
		return;
	}

	CString strInput;
	GetDlgItem(IDC_CONTEXT)->GetWindowText(strInput);

	BinaryData binData;
	if(!Utility::ConvertHexToBinary(strInput, binData))
	{
		::AfxMessageBox("Invalidate Format!");
		return;
	}

	BinaryCommand cmd(binData);
	U08* pCmd = cmd.GetBuffer();
	int inSize = cmd.Size();
	CGPSDlg::gpsDlg->m_serial->SendData(pCmd, inSize);
}
