#include "pch.h"
#include "CCore.h"

#include "CTimeMgr.h"
#include "CSceneMgr.h"
#include "CPathMgr.h"
#include "CKeyMgr.h"
#include "CCollisionMgr.h"



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

	for (int i = 0; i < (int)PEN_TYPE::END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}
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





	CreatePenBrush();

	CTimeMgr::GetInst()->init();
	CPathMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CSceneMgr::GetInst()->init();


	return S_OK;
}

void CCore::progress()
{
	//====================
	//=====  update  =====
	//====================

	CTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();
	CSceneMgr::GetInst()->update();
	CCollisionMgr::GetInst()->update();




	//=====================
	//===== rendering =====
	//=====================


	Rectangle(m_hMemdc, -1, -1, (int)m_vResolution.x + 1, (int)m_vResolution.y + 1);

	CSceneMgr::GetInst()->render(m_hMemdc);

	BitBlt(m_hdc, 0, 0, (int)m_vResolution.x, (int)m_vResolution.y, m_hMemdc, 0, 0, SRCCOPY);

	CTimeMgr::GetInst()->render();
}

void CCore::CreatePenBrush()
{
	// Create Brush
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	m_arrBrush[(UINT)BRUSH_TYPE::WHITE] = (HBRUSH)GetStockObject(WHITE_BRUSH);
	m_arrBrush[(UINT)BRUSH_TYPE::BLACK] = (HBRUSH)GetStockObject(BLACK_BRUSH);

	// Create Pen
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}