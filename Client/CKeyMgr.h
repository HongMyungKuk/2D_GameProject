#pragma once

enum class KEY_STATE
{
	TAP,
	HOLD,
	AWAY,
	NONE
};

enum class KEY
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	W,
	S,
	A,
	D,
	TAB,
	SPACE,
	ENTER,
	ESC,

	LAST
};

struct tagKeyInfo
{
	KEY_STATE eState;
	bool	  bPrevKeyDown;
};

class CKeyMgr
{
	SINGLE(CKeyMgr);
private:
	tagKeyInfo m_arrKeyInfo[(UINT)KEY::LAST];

public:
	KEY_STATE GetKeyState(KEY _eKey) const { return m_arrKeyInfo[(UINT)_eKey].eState; }

public:
	void init();
	void update();
};

