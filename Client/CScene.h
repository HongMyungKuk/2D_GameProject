#pragma once

class CObject;

class CScene
{
private:
	vector<CObject*> m_vecGroupObj[(UINT)GROUP_TYPE::END];

public:
	void AddGroupObj(CObject* _pObj, GROUP_TYPE _eType) { m_vecGroupObj[(UINT)_eType].push_back(_pObj); }

	vector<CObject*>& GetGroupObj(GROUP_TYPE _eType) { return m_vecGroupObj[(UINT)_eType]; }

public:
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	virtual void update();
	virtual void render(HDC _hdc);

public:
	CScene();
	virtual ~CScene();
};

