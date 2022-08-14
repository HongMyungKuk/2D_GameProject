#include "pch.h"
#include "CResMgr.h"
#include "CTexture.h"

#include "CPathMgr.h"

CResMgr::CResMgr()
{

}

CResMgr::~CResMgr()
{
	Safe_Delete_map(m_mapRes);
}

CTexture* CResMgr::LoadTexture(const wstring& _strName, const wstring& _strPath)
{
	CTexture* pTex = FindTexture(_strName);
	if (pTex != nullptr)
	{
		return pTex;
	}
	wstring strPath = CPathMgr::GetInst()->GetPath() + _strPath;

	pTex = new CTexture;
	pTex->SetName(_strName);
	pTex->SetPath(strPath);
	pTex->Load(strPath);

	m_mapRes.insert(make_pair(_strName, pTex));

	return pTex;
}

CTexture* CResMgr::FindTexture(const wstring& _strName)
{
	map<wstring, CRes*>::iterator iter = m_mapRes.find(_strName);

	if (iter == m_mapRes.end())
	{
		return nullptr;
	}

	return (CTexture*)iter->second;
}
