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

	HPEN		m_arrPen[(UINT)PEN_TYPE::END];
	HBRUSH		m_arrBrush[(UINT)BRUSH_TYPE::END];

public:
	void CreatePenBrush();

public:
	HWND GetMainWnd() const { return m_hWnd; }
	HDC GetMainDC() const { return m_hdc; }
	Vec2 GetResolution() const { return m_vResolution; }
	HPEN GetPen(PEN_TYPE _eType) const { return m_arrPen[(UINT)_eType]; }
	HBRUSH GetBrush(BRUSH_TYPE _eType) const { return m_arrBrush[(UINT)_eType]; }

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();
};

