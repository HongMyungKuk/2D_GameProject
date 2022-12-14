#include "pch.h"
#include "CPlayer.h"

#include "CTimeMgr.h"
#include "CResMgr.h"
#include "CKeyMgr.h"

#include "CTexture.h"
#include "CCollider.h"

CPlayer::CPlayer()
	: m_pTex(nullptr)
{
	// Texture
	m_pTex = CResMgr::GetInst()->LoadTexture(L"Player", L"Texture\\Player_Sonic_Idle.bmp");

	// Collider
	CreateCollider();
	GetCollider()->SetScale(Vec2(100.f, 100.f));
	GetCollider()->SetOffSet(Vec2(0.f, 0.f));
}

CPlayer::~CPlayer()
{
}

void CPlayer::update()
{
	Vec2 vPos = GetPos();

	if (KEY_HOLD(KEY::UP))
	{
		vPos.y -= 500.f * fDT;
	}

	if (KEY_HOLD(KEY::DOWN))
	{
		vPos.y += 500.f * fDT;
	}

	if (KEY_HOLD(KEY::LEFT))
	{
		vPos.x -= 500.f * fDT;
	}

	if (KEY_HOLD(KEY::RIGHT))
	{
		vPos.x += 500.f * fDT;
	}

	SetPos(vPos);
}

void CPlayer::render(HDC _hdc)
{
	component_render(_hdc);

	Vec2 vPos = GetPos();

	int iHeight = m_pTex->Height();
	int iWidth = m_pTex->Width();

	// 4.f => extra gap
	Vec2 vSlice = Vec2((float)iWidth / 8.f - 4.f, (float)iHeight); 

	Vec2 vLT = vPos - vSlice / 2.f;

	TransparentBlt(_hdc
		, (int)vLT.x, (int)vLT.y
		, (int)vSlice.x, (int)vSlice.y
		, m_pTex->GetDC()
		, 0, 0
		, (int)vSlice.x, (int)vSlice.y
		, RGB(38, 123, 218));
}

void CPlayer::OnCollisionEnter(CCollider* _pOther)
{
}

void CPlayer::OnCollision(CCollider* _pOther)
{
}

void CPlayer::OnCollisonExit(CCollider* _pOther)
{
}
