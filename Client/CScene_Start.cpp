#include "pch.h"
#include "CScene_Start.h"
#include "CCore.h"

#include "CCollisionMgr.h"

#include "CObject.h"
#include "CPlayer.h"
#include "CMonster.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
	Vec2 vResolution = CCore::GetInst()->GetResolution();

	// Create Player
	CObject* pObj = new CPlayer;
	pObj->SetName(L"Player");
	pObj->SetPos(Vec2(50.f, vResolution.y / 2.f));
	pObj->SetScale(Vec2(50.f, 50.f));
	AddGroupObj(pObj, GROUP_TYPE::PLAYER);

	// Clone
	//CObject* pObj2  = pObj->Clone();
	//pObj2->SetPos(Vec2(50.f + 100.f, vResolution.y / 2.f));
	//AddGroupObj(pObj2, GROUP_TYPE::PLAYER);


	// Create Monster
	pObj = new CMonster;
	pObj->SetName(L"Monster");
	pObj->SetPos(Vec2(vResolution.x - 50.f, vResolution.y / 2.f));
	pObj->SetScale(Vec2(50.f, 50.f));
	AddGroupObj(pObj, GROUP_TYPE::MONSTER);

	// Add Collision 
	CCollisionMgr::GetInst()->CheckCollision(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
}

void CScene_Start::Exit()
{
}

