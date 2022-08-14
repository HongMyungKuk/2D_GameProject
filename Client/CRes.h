#pragma once

class CRes
{
private:
	wstring m_strName;
	wstring m_strPath;

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	void SetPath(const wstring& _strPath) { m_strPath = _strPath; }

public:
	CRes();
	virtual ~CRes();
};

