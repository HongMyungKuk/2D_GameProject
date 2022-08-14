#include "pch.h"
#include "CSceneMgr.h"
#include "CScene.h"
#include "CScene_Tool.h"
#include "CScene_Start.h"

#include "CCollisionMgr.h"

CSceneMgr::CSceneMgr()
	: m_pCurScene(nullptr)
{
}

CSceneMgr::~CSceneMgr()
{
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (m_arrScene[i] != nullptr)
		{
			delete m_arrScene[i];
			m_arrScene[i] = nullptr;
		}
	}
}

void CSceneMgr::init()
{
	m_arrScene[(UINT)SCENE_TYPE::TOOL_SCENE] = new CScene_Tool;
	m_arrScene[(UINT)SCENE_TYPE::START_SCENE] = new CScene_Start;

	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START_SCENE];

	m_pCurScene->Enter();
}

void CSceneMgr::update()
{
	if (m_pCurScene != nullptr)
	{
		m_pCurScene->update();
		m_pCurScene->final_update();
	}
}

void CSceneMgr::render(HDC _hdc)
{
	if (m_pCurScene != nullptr)
		m_pCurScene->render(_hdc);
}


