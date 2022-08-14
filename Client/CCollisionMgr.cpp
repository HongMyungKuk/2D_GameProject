#include "pch.h"
#include "CCollisionMgr.h"

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
				CollisionGroupUpdate(iRow, iCol);
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

void CCollisionMgr::CollisionGroupUpdate(int _iLeft, int _iRight)
{
}
