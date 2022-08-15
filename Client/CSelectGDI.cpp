#include "pch.h"
#include "CSelectGDI.h"
#include "CCore.h"

CSelectGDI::CSelectGDI(HDC _hdc, PEN_TYPE _eType)
	: m_hdc(0)
	, m_hDefaultPen(0)
	, m_hDefaultBrush(0)
{
	m_hdc = _hdc;
	HPEN hPen = CCore::GetInst()->GetPen(_eType);
	m_hDefaultPen = (HPEN)SelectObject(_hdc, hPen);
}

CSelectGDI::CSelectGDI(HDC _hdc, BRUSH_TYPE _eType)
	: m_hdc(0)
	, m_hDefaultPen(0)
	, m_hDefaultBrush(0)
{
	m_hdc = _hdc;
	HBRUSH hPen = CCore::GetInst()->GetBrush(_eType);
	m_hDefaultBrush = (HBRUSH)SelectObject(_hdc, hPen);
}

CSelectGDI::~CSelectGDI()
{
	SelectObject(m_hdc, m_hDefaultPen);
	SelectObject(m_hdc, m_hDefaultBrush);
}
