#include "pch.h"
#include "CCore.h"

#include "CTimeMgr.h"

Vec2 vPos = { 1280.f / 2.f, 800.f / 2.f };
Vec2 vScale = { 100.f, 100.f };


CCore::CCore()
	: m_hWnd(nullptr)
	, m_hdc(nullptr)
	, m_hMemdc(nullptr)
	, m_hBitmap(nullptr)
	, m_vResolution{}
{

}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hdc);
	DeleteObject(m_hBitmap);
	DeleteDC(m_hMemdc);


}

int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_vResolution = _ptResolution;

	// DC 
	m_hdc = GetDC(_hWnd);
	m_hBitmap = CreateCompatibleBitmap(m_hdc, _ptResolution.x, _ptResolution.y);
	m_hMemdc = CreateCompatibleDC(m_hdc);
	HBITMAP hOldBitMap = (HBITMAP)SelectObject(m_hMemdc, m_hBitmap);
	DeleteObject(hOldBitMap);


 
	RECT rt = { 0, 0, (LONG)m_vResolution.x, (LONG)m_vResolution.y };

	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	CTimeMgr::GetInst()->init();

	return S_OK;
}

void CCore::progress()
{
	// update
	CTimeMgr::GetInst()->update();

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		vPos.y -= 100.f * fDT;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		vPos.y += 100.f * fDT;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= 100.f * fDT;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 100.f * fDT;
	}

	// render

	Rectangle(m_hMemdc, -1, -1, m_vResolution.x + 1, m_vResolution.y + 1);

	Rectangle(m_hMemdc
		, int(vPos.x - vScale.x / 2.f)
		, int(vPos.y - vScale.y / 2.f)
		, int(vPos.x + vScale.x / 2.f)
		, int(vPos.y + vScale.y / 2.f));

	BitBlt(m_hdc
		, 0, 0
		, (int)m_vResolution.x
		, (int)m_vResolution.y
		, m_hMemdc
		, 0, 0
		, SRCCOPY);

	CTimeMgr::GetInst()->render();
}
