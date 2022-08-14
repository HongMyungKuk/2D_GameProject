#pragma once

class CMonster
{
public:
	virtual void update();
	virtual void render(HDC _hdc);
	
public:
	CMonster();
	~CMonster();
};

