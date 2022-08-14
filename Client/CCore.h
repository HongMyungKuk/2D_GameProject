#pragma once

class CCore
{
	SINGLE(CCore);
private:
	HWND		m_hWnd;
	HDC			m_hdc;
	HDC			m_hMemdc;
	HBITMAP		m_hBitmap;
	Vec2		m_vResolution;

public:
	HWND GetMainWnd() const { return m_hWnd; }
	HDC GetMainDC() const { return m_hdc; }
	Vec2 GetResolution() const { return m_vResolution; }

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();
};

