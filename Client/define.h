#pragma once

// Sington
#define SINGLE(type)\
public:\
	static type* GetInst()\
	{\
		static type s_pInst;\
		return &s_pInst;\
	}\
private:\
	type();\
	~type();




// Time Manager Comfortable define
#define DT CTimeMgr::GetInst()->GetDeltaTime()
#define fDT CTimeMgr::GetInst()->GetFDeltaTime()

// Key Manager Comfortable define
#define KEY(dir, state) CKeyMgr::GetInst()->GetKeyState(dir) == state
#define KEY_HOLD(dir) KEY(dir, KEY_STATE::HOLD)
#define KEY_AWAY(dir) KEY(dir, KEY_STATE::AWAY)
#define KEY_NONE(dir) KEY(dir, KEY_STATE::NONE)



// Type
enum class GROUP_TYPE
{
	PLAYER,
	MONSTER,
	MISSILE,

	END = 32
};

enum class SCENE_TYPE
{
	TOOL_SCENE,
	START_SCENE,

	END
};

enum class PEN_TYPE
{
	RED,
	BLUE,
	GREEN,

	END
};

enum class BRUSH_TYPE
{
	HOLLOW,
	WHITE,
	BLACK,

	END
};

