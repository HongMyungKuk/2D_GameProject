#pragma once

class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hWnd;
	HDC     m_hdc;
	Vec2    m_vResolution;


public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();
};

