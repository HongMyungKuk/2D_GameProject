#pragma once

class CSelectGDI
{
private:
	HDC     m_hdc;
	HPEN	m_hDefaultPen;
	HBRUSH  m_hDefaultBrush;

public:
	CSelectGDI(HDC _hdc, PEN_TYPE _eType);
	CSelectGDI(HDC _hdc, BRUSH_TYPE _eType);
	~CSelectGDI();
};

