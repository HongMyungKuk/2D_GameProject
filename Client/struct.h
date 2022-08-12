#pragma once
#include <Windows.h>

struct Vec2
{
	float x;
	float y;
	
	Vec2() 
		: x(0.f)
		, y(0.f)
	{
	}

	Vec2(const Vec2& _v)
		: x(_v.x)
		, y(_v.y)
	{
	}

	Vec2(const POINT& _pt)
		: x((float)_pt.x)
		, y((float)_pt.y)
	{
	}

	Vec2(float _x, float _y)
		: x(_x)
		, y(_y)
	{
	}

	Vec2 operator = (const POINT& _pt)
	{
		x = (float)_pt.x;
		y = (float)_pt.y;

		return Vec2(x, y);
	}
};