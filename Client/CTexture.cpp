#include "pch.h"
#include "CTexture.h"
#include "CCore.h"

CTexture::CTexture()
	: m_hdc(nullptr)
	, m_hBitmap(nullptr)
	, m_tBitInfo{}
{
}

CTexture::~CTexture()
{
	DeleteObject(m_hBitmap);
	DeleteDC(m_hdc);
}

void CTexture::Load(const wstring& _strPath)
{
	m_hBitmap = (HBITMAP)LoadImage(nullptr, _strPath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hBitmap);
	
	m_hdc = CreateCompatibleDC(CCore::GetInst()->GetMainDC());
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hdc, m_hBitmap);
	DeleteObject(hOldBitmap);

	GetObject(m_hBitmap, sizeof(m_tBitInfo), &m_tBitInfo);
}
