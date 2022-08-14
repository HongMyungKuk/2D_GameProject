#pragma once
#include <Windows.h>
#include <assert.h>

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

	Vec2 operator + (const Vec2& _v)
	{
		Vec2 v;
		v.x = x + _v.x;
		v.y = y + _v.y;
		return v;
	}

	Vec2 operator - (const Vec2& _v)
	{
		Vec2 v;
		v.x = x - _v.x;
		v.y = y - _v.y;
		return v;
	}

	Vec2 operator * (const Vec2& _v)
	{
		Vec2 v;
		v.x = x * _v.x;
		v.y = y * _v.y;
		return v;
	}

	Vec2 operator / (const Vec2& _v)
	{
		assert(!(_v.x == 0 || _v.y == 0));
		Vec2 v;
		v.x = x / _v.x;
		v.y = y / _v.y;
		return v;
	}

	Vec2 operator / (float _f)
	{
		assert(_f);
		Vec2 v;
		v.x = x / _f;
		v.y = y / _f;
		return v;
	}
};