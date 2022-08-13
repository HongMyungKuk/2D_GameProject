#include "pch.h"
#include "CScene_Start.h"
#include "CObject.h"
#include "CCore.h"


CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
	Vec2 vResolution = CCore::GetInst()->GetResolution();

	CObject* pObj = new CObject;
	pObj->SetName(L"Player");
	pObj->SetPos(Vec2(vResolution.x / 2.f, vResolution.y / 2.f));
	pObj->SetScale(Vec2(50.f, 50.f));

	AddGroupObj(pObj, GROUP_TYPE::PLAYER);
}

void CScene_Start::Exit()
{
}

