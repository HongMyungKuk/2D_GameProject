#pragma once

class CRes;
class CTexture;

class CResMgr
{
	SINGLE(CResMgr);
private:
	map<wstring, CRes*> m_mapRes;

public:
	CTexture* LoadTexture(const wstring& _strName, const wstring& _strPath);
	CTexture* FindTexture(const wstring& _strName);
};

