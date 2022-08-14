#include "pch.h"
#include "CObject.h"

#include "CResMgr.h"
#include "CTexture.h"
#include "CCollider.h"

CObject::CObject()
	: m_vPos{}
	, m_vScale{}
	, m_pCollider(nullptr)
{
}

CObject::~CObject()
{
	if (m_pCollider != nullptr)
		delete m_pCollider;
}

void CObject::update()
{
}

void CObject::final_update()
{
	if (m_pCollider != nullptr)
	{
		m_pCollider->final_update();
	}
}

void CObject::render(HDC _hdc)
{
	Rectangle(_hdc
		, (int)(m_vPos.x - m_vScale.x / 2.f)
		, (int)(m_vPos.y - m_vScale.y / 2.f)
		, (int)(m_vPos.x + m_vScale.x / 2.f)
		, (int)(m_vPos.y + m_vScale.y / 2.f));
}

void CObject::component_render(HDC _hdc)
{
	if (m_pCollider != nullptr)
	{
		m_pCollider->render(_hdc);
	}
}

void CObject::CreateCollider()
{
	if (m_pCollider == nullptr)
	{
		m_pCollider = new CCollider;
		m_pCollider->m_pOwner = this;
	}
}



