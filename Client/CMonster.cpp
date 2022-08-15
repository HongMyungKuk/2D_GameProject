#include "pch.h"
#include "CMonster.h"
#include "CCollider.h"

CMonster::CMonster()
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(100.f, 100.f));
	GetCollider()->SetOffSet(Vec2(0.f, 0.f));
}

CMonster::~CMonster()
{
}

void CMonster::update()
{
}

void CMonster::render(HDC _hdc)
{
	component_render(_hdc);

	CObject::render(_hdc);
}

void CMonster::OnCollisionEnter(CCollider* _pOther)
{
}

void CMonster::OnCollision(CCollider* _pOther)
{
}

void CMonster::OnCollisonExit(CCollider* _pOther)
{
}



