#include "pch.h"
#include "CCollider.h"
#include "CObject.h"

#include "CSelectGDI.h"

UINT CCollider::s_iID = 0;

CCollider::CCollider()
	: m_pOwner(nullptr)
	, m_vFinalPos{}
	, m_vScale{}
	, m_vOffSet{}
	, m_iID(s_iID++)
	, m_bFlag(false)
{
}

CCollider::CCollider(const CCollider& _copy)
	: m_pOwner(nullptr)
	, m_vFinalPos(_copy.m_vFinalPos)
	, m_vScale(_copy.m_vScale)
	, m_vOffSet(_copy.m_vOffSet)
	, m_iID(s_iID++)
	, m_bFlag(false)
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
	PEN_TYPE _eType;

	if (m_bFlag == true)
	{
		_eType = PEN_TYPE::RED;
	}
	else
	{
		_eType = PEN_TYPE::GREEN;
	}

	CSelectGDI s1(_hdc, BRUSH_TYPE::HOLLOW);
	CSelectGDI s2(_hdc, _eType);

	Rectangle(_hdc
		, (int)(m_vFinalPos.x - m_vScale.x / 2.f)
		, (int)(m_vFinalPos.y - m_vScale.y / 2.f)
		, (int)(m_vFinalPos.x + m_vScale.x / 2.f)
		, (int)(m_vFinalPos.y + m_vScale.y / 2.f));
}

void CCollider::OnCollisionEnter(CCollider* _pOther)
{
	m_bFlag = true;
	m_pOwner->OnCollisionEnter(_pOther);
}

void CCollider::OnCollision(CCollider* _pOther)
{
	m_pOwner->OnCollision(_pOther);
}

void CCollider::OnCollisionExit(CCollider* _pOther)
{
	m_bFlag = false;
	m_pOwner->OnCollisonExit(_pOther);
}

