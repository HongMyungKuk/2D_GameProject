#pragma once

class CObject
{
private:
	wstring m_strName;
	Vec2    m_vPos;
	Vec2    m_vScale;

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	const wstring& GetName() const { return m_strName; }
	Vec2 GetPos() const { return m_vPos; }
	Vec2 GetScale() const { return m_vScale; }

public:
	virtual void update();
	virtual void render(HDC _hdc);

public:
	CObject();
	virtual ~CObject();
};

