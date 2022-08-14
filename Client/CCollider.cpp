#include "pch.h"
#include "CCollider.h"
#include "CObject.h"


CCollider::CCollider()
	: m_pOwner(nullptr)
	, m_vFinalPos{}
	, m_vScale{}
	, m_vOffSet{}
{
}

CCollider::~CCollider()
{
}

void CCollider::final_update()
{
	Vec2 vPos = m_pOwner->GetPos();
	m_vFinalPos = vPos + m_vOffSet;
}

void CCollider::render(HDC _hdc)
{
	Rectangle(_hdc
		, m_vFinalPos.x - m_vScale.x / 2.f
		, m_vFinalPos.y - m_vScale.y / 2.f
		, m_vFinalPos.x + m_vScale.x / 2.f
		, m_vFinalPos.y + m_vScale.y / 2.f);
}

