#pragma once

class CCollider;

union COLLISION_ID
{
	struct
	{
		UINT iLeftID;
		UINT iRightID;
	};
	LONGLONG ID;
};





class CCollisionMgr
{
	SINGLE(CCollisionMgr);
public:
	UINT						m_arrCheckCollision[(UINT)GROUP_TYPE::END];
	map<LONGLONG, bool>			m_mapPrevCollision;

public:
	void CheckCollision(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	void CollisionGroupUpdate(GROUP_TYPE _iLeft, GROUP_TYPE _iRight);
	bool IsCollision(CCollider* _pLeft, CCollider* _pRight);

public:
	void update();
};

