#include "pch.h"
#include "CScene.h"
#include "CObject.h"

CScene::CScene()
{
}

CScene::~CScene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		Safe_Delete_Vector(m_vecGroupObj[i]);
	}
}

void CScene::update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_vecGroupObj[i].size(); ++j)
		{
			m_vecGroupObj[i][j]->update();
		}
	}
}

void CScene::render(HDC _hdc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_vecGroupObj[i].size(); ++j)
		{
			m_vecGroupObj[i][j]->render(_hdc);
		}
	}
}
