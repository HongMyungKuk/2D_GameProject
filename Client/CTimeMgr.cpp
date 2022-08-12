#include "pch.h"
#include "CTimeMgr.h"
#include "CCore.h"

CTimeMgr::CTimeMgr()
	: m_llPrevCount{}
	, m_llCurCount{}
	, m_llFrequency{}
	, m_dDT(0.0)
	, m_iFPS(0)
	, m_dAccTime(0.f)
{

}

CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
	QueryPerformanceCounter(&m_llPrevCount);
	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);

	// x : m_llCurCount - m_llPrevCount = 1 : m_llFrequency
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)m_llFrequency.QuadPart;
	m_llPrevCount = m_llCurCount;
}

void CTimeMgr::render()
{
	m_dAccTime += m_dDT;
	m_iFPS++;

	if (m_dAccTime > 1.0)
	{
		wchar_t buf[32] = {};
		swprintf_s(buf, L"FPS : %d, DT : %f", m_iFPS, m_dDT);
		m_iFPS = 0;
		m_dAccTime = 0.0;
		
		SetWindowText(CCore::GetInst()->GetMainWnd(), buf);
	}
}


