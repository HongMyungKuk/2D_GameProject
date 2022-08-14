#pragma once


class CCollisionMgr
{
	SINGLE(CCollisionMgr);
public:
	UINT m_arrCheckCollision[(UINT)GROUP_TYPE::END];

public:
	void CheckCollision(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	void CollisionGroupUpdate(int _iLeft, int _iRight);

public:
	void update();
};

