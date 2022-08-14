#include "pch.h"
#include "CKeyMgr.h"

int g_arrKey[(UINT)KEY::LAST] =
{
	VK_UP,
	VK_DOWN,
	VK_LEFT,
	VK_RIGHT,
	'W',
	'S',
	'A',
	'D',
	VK_TAB,
	VK_SPACE,
	VK_RETURN,
	VK_ESCAPE,
};

CKeyMgr::CKeyMgr()
	: m_arrKeyInfo{}
{

}

CKeyMgr::~CKeyMgr()
{

}

void CKeyMgr::init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		m_arrKeyInfo[i].eState = KEY_STATE::NONE;
		m_arrKeyInfo[i].bPrevKeyDown = false;
	}
}

void CKeyMgr::update()
{
	HWND hWnd = GetFocus();

	// Window Focusing State
	if (hWnd)
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			if (GetAsyncKeyState(g_arrKey[i]) & 0x8000)
			{
				if (m_arrKeyInfo[i].bPrevKeyDown == true)
				{
					m_arrKeyInfo[i].eState = KEY_STATE::HOLD;
				}
				else
				{
					m_arrKeyInfo[i].eState = KEY_STATE::TAP;
				}
				m_arrKeyInfo[i].bPrevKeyDown = true;
			}
			else
			{
				if (m_arrKeyInfo[i].bPrevKeyDown == true)
				{
					m_arrKeyInfo[i].eState = KEY_STATE::AWAY;
				}
				else
				{
					m_arrKeyInfo[i].eState = KEY_STATE::NONE;
				}
				m_arrKeyInfo[i].bPrevKeyDown = false;
			}
		}
	}
	// not Focusing
	else
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			if (m_arrKeyInfo[i].eState == KEY_STATE::HOLD || m_arrKeyInfo[i].eState == KEY_STATE::TAP)
			{
				m_arrKeyInfo[i].eState = KEY_STATE::AWAY;
			}
			else if (m_arrKeyInfo[i].eState == KEY_STATE::AWAY)
			{
				m_arrKeyInfo[i].eState = KEY_STATE::NONE;
			}
		}
	}
}
