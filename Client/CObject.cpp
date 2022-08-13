#include "pch.h"
#include "CObject.h"
#include "CTimeMgr.h"


CObject::CObject()
	: m_vPos{}
	, m_vScale{}
{
}

CObject::~CObject()
{
}

void CObject::update()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_vPos.y -= 100.f * fDT;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_vPos.y += 100.f * fDT;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_vPos.x -= 100.f * fDT;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_vPos.x += 100.f * fDT;
	}
}

void CObject::render(HDC _hdc)
{
	Rectangle(_hdc
		, int(m_vPos.x - m_vScale.x / 2.f)
		, int(m_vPos.y - m_vScale.y / 2.f)
		, int(m_vPos.x + m_vScale.x / 2.f)
		, int(m_vPos.y + m_vScale.y / 2.f));
}


