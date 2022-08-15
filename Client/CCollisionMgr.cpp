#include "pch.h"
#include "CCollisionMgr.h"
#include "CSceneMgr.h"

#include "CScene.h"
#include "CObject.h"
#include "CCollider.h"

CCollisionMgr::CCollisionMgr()
	: m_arrCheckCollision{}
{

}

CCollisionMgr::~CCollisionMgr()
{

}

void CCollisionMgr::update()
{
	for (int iRow = 0; iRow < (int)GROUP_TYPE::END; ++iRow)
	{
		for (int iCol = iRow; iCol < (int)GROUP_TYPE::END; ++iCol)
		{
			if (m_arrCheckCollision[iRow] & (1 << iCol))
			{
				CollisionGroupUpdate((GROUP_TYPE)iRow, (GROUP_TYPE)iCol);
			}
		}
	}
}

void CCollisionMgr::CheckCollision(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	int iRow = (int)_eLeft;
	int iCol = (int)_eRight;

	if (iRow > iCol)
	{
		iRow = (int)_eRight;
		iCol = (int)_eLeft;
	}

	if (m_arrCheckCollision[iRow] & (1 << iCol))
	{
		m_arrCheckCollision[iRow] &= ~(1 << iCol);
	}
	else
	{
		m_arrCheckCollision[iRow] |= (1 << iCol);
	}
}

void CCollisionMgr::CollisionGroupUpdate(GROUP_TYPE _iLeft, GROUP_TYPE _iRight)
{
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
	const vector<CObject*>& vecLeft = pCurScene->GetGroupObj(_iLeft);
	const vector<CObject*>& vecRight = pCurScene->GetGroupObj(_iRight);

	for (size_t i = 0; i < vecLeft.size(); ++i)
	{
		if (vecLeft[i]->GetCollider() == nullptr)
		{
			continue;
		}

		for (size_t j = 0; j < vecRight.size(); ++j)
		{
			if (vecRight[j]->GetCollider() == nullptr || vecLeft[i] == vecRight[j])
			{
				continue;
			}

			CCollider* pLeft = vecLeft[i]->GetCollider();
			CCollider* pRight = vecRight[j]->GetCollider();

			COLLISION_ID ID = {};

			ID.iLeftID = pLeft->GetID();
			ID.iRightID = pRight->GetID();

			map<LONGLONG, bool>::iterator iter = m_mapPrevCollision.find(ID.ID);

			if (iter == m_mapPrevCollision.end())
			{
				m_mapPrevCollision.insert(make_pair(ID.ID, false));
				iter = m_mapPrevCollision.find(ID.ID);
			}

			if (IsCollision(pLeft, pRight))
			{
				if (iter->second == true)
				{
					pLeft->OnCollision(pRight);
					pRight->OnCollision(pLeft);
				}
				else
				{
					pLeft->OnCollisionEnter(pRight);
					pRight->OnCollisionEnter(pLeft);
				}
				iter->second = true;
			}
			else
			{
				if (iter->second == true)
				{
					pLeft->OnCollisionExit(pRight);
					pRight->OnCollisionExit(pLeft);
				}
				iter->second = false;
			}
		}
	}
}

bool CCollisionMgr::IsCollision(CCollider* _pLeft, CCollider* _pRight)
{
	Vec2 vLeftPos = _pLeft->GetFinalPos();
	Vec2 vLeftScale = _pLeft->GetScale();

	Vec2 vRightPos = _pRight->GetFinalPos();
	Vec2 vRightScale = _pRight->GetScale();

	if (abs(vLeftPos.x - vRightPos.x) <= (vLeftScale.x + vRightScale.x) / 2.f
		&& abs(vLeftPos.y - vRightPos.y) <= (vLeftScale.y + vRightScale.y) / 2.f)
	{
		return true;
	}

	return false;
}
