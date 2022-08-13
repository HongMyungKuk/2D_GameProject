#pragma once

class CScene;

// Stats Pattern
class CSceneMgr
{
	SINGLE(CSceneMgr);
	
private:
	CScene*		m_arrScene[(UINT)SCENE_TYPE::END];
	CScene*		m_pCurScene;

public:
	void init();
	void update();
	void render(HDC _hdc);
};

