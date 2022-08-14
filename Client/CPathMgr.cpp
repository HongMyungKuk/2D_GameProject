#include "pch.h"
#include "CPathMgr.h"

CPathMgr::CPathMgr()
	: m_szContentPath{}
{

}

CPathMgr::~CPathMgr()
{

}

void CPathMgr::init()
{
	GetCurrentDirectory(256, m_szContentPath);
	int iLen = (int)wcslen(m_szContentPath);

	for (int i = iLen - 1; i >= 0; --i)
	{
		if (m_szContentPath[i] == L'\\')
		{
			m_szContentPath[i] = L'\0';
			break;
		}
	}
	
	wcscat_s(m_szContentPath, L"\\bin\\Resource\\");
}
