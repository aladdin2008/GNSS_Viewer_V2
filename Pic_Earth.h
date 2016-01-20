#pragma once

class UISetting;
struct Satellite;
struct GPGSV;
struct GPGSA;
struct GPGGA;
class CPic_Earth : public CStatic
{
public:
	CPic_Earth(void);
	~CPic_Earth(void);

	CButton m_gpCheck;
	CButton m_glCheck;
	CButton m_bdCheck;
	CButton m_gaCheck;

private:
	void Refresh_EarthChart(CDC *dc);
	void Show_EarthChart(CDC *dc);
	void DrawEarthSate(CDC* dc, UISetting* s, Satellite* sate, GPGSV* gsv, GPGSA* gsa, GPGGA* gga);

	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();

	void InitCheck();
	bool m_first;
};
