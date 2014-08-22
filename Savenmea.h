#pragma once
//#include "afxwin.h"
//#include "afxcmn.h"


// CSavenmea ��ܤ��

class CSaveNmea : public CDialog
{
	DECLARE_DYNAMIC(CSaveNmea)

public:
	CSaveNmea(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CSaveNmea();

	enum EventType
	{
		StopWriteNmea,
		ClickClose,
	};
	// ��ܤ�����
	//enum { IDD = IDD_SAVENMEA };
	UINT RegisterEventMessage() 
	{	
		m_dialogEvent = ::RegisterWindowMessage("CSaveNmea-Event");
		return m_dialogEvent; 
	}
	void SetNotifyWindow(HWND h) { m_notifyWindow = h; };
	void Initialize(LPCSTR nmeaFile);
	//void DisplaySize(int size);
	void StartSave(LPCSTR title, LPCSTR filePath);
	void StopSave() { isNmeaFileOpen = false; }
	void WriteFile(void* p, int len);

	static bool IsNmeaFileOpen() { return isNmeaFileOpen; }
	static bool IsPressNmeaCommend() { return isPressNmeaCommend; }
	static bool SaveData(void* p, int len);
	static bool SaveText(void* p, int len);
	static bool SaveBinary(void* p, int len);
	static void SetBinaryMode(bool b) { isBinaryMode = b; }

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void PostNcDestroy();
public:
	afx_msg void OnBnClickedContinue();
	afx_msg void OnBnClickedStop();
	afx_msg void OnBnClickedClose();
	
protected:
	CString m_filePath;
	UINT m_dialogEvent;
	HWND m_notifyWindow;

	//int	m_nmeaFileSize;
	static bool isNmeaFileOpen;	
	static bool isPressNmeaCommend;
	static CSaveNmea* sthis;
	static bool isBinaryMode;
//public:
//	afx_msg void OnClose();
};

class CPlayNmea : public CDialog
{
	DECLARE_DYNAMIC(CPlayNmea)

public:
	CPlayNmea(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CPlayNmea();

	enum EventType
	{
		IntervalChange,
		PauseStatus,
		ClickClose,
	};
// ��ܤ�����
	enum { IDD = IDD_PLAY_NMEA };

	UINT RegisterEventMessage();
	void SetNotifyWindow(HWND h) { m_notifyWindow = h; };

	void Initialize(LPCSTR nmeaFile);
	int GetPlayInterval();
	void SetLineCount(int count, long size, long total);

protected:
	UINT m_dialogEvent;
	HWND m_notifyWindow;

	CSliderCtrl m_playIntervalSlider;
	bool m_isPlayControlInPause;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void PostNcDestroy();
public:
	afx_msg void OnBnClickedClose();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedPlayControl();
	afx_msg void OnBnClickedTimeSync();
};
