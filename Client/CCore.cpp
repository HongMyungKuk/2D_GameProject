#include "pch.h"
#include "CCore.h"

#include "CTimeMgr.h"
#include "CSceneMgr.h"

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

	// DC (Double Buffering)
	m_hdc = GetDC(_hWnd);
	m_hBitmap = CreateCompatibleBitmap(m_hdc, _ptResolution.x, _ptResolution.y);
	m_hMemdc = CreateCompatibleDC(m_hdc);
	HBITMAP hOldBitMap = (HBITMAP)SelectObject(m_hMemdc, m_hBitmap);
	DeleteObject(hOldBitMap);


 
	RECT rt = { 0, 0, (LONG)m_vResolution.x, (LONG)m_vResolution.y };

	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	CTimeMgr::GetInst()->init();
	CSceneMgr::GetInst()->init();

	return S_OK;
}

void CCore::progress()
{
	//====================
	//=====  update  =====
	//====================

	CTimeMgr::GetInst()->update();
	CSceneMgr::GetInst()->update();







	//=====================
	//===== rendering =====
	//=====================


	Rectangle(m_hMemdc, -1, -1, (int)m_vResolution.x + 1, (int)m_vResolution.y + 1);

	CSceneMgr::GetInst()->render(m_hMemdc);

	BitBlt(m_hdc, 0, 0, (int)m_vResolution.x, (int)m_vResolution.y, m_hMemdc, 0, 0, SRCCOPY);

	CTimeMgr::GetInst()->render();
}
