#include "pch.h"
#include "CCore.h"

Vec2 vPos = { 1280.f / 2.f, 800.f / 2.f };
Vec2 vScale = { 100.f, 100.f };


CCore::CCore()
	: m_hWnd(nullptr)
	, m_hdc(nullptr)
	, m_vResolution{}
{

}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hdc);
}

int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_hdc = GetDC(_hWnd);

	m_vResolution = _ptResolution;

	RECT rt = { 0, 0, (LONG)m_vResolution.x, (LONG)m_vResolution.y };

	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	//haha
	//hello


	return S_OK;
}

void CCore::progress()
{
	static int iCount = 0;
	iCount++;

	static LONGLONG llPrevCount = GetTickCount64();
	LONGLONG llCurCount = GetTickCount64();

	if (llCurCount - llPrevCount > 1000)
	{
		iCount;
		llPrevCount = llCurCount;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		vPos.y -= 0.01f;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		vPos.y += 0.01f;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= 0.01f;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 0.01f;
	}
	
	Rectangle(m_hdc
		, int(vPos.x - vScale.x / 2.f)
		, int(vPos.y - vScale.y / 2.f)
		, int(vPos.x + vScale.x / 2.f)
		, int(vPos.y + vScale.y / 2.f));
}
