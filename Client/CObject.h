#pragma once

class CCollider;

class CObject
{
private:
	wstring		m_strName;
	Vec2		m_vPos;
	Vec2		m_vScale;
	
	CCollider*	m_pCollider;

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	const wstring& GetName() const { return m_strName; }
	Vec2 GetPos() const { return m_vPos; }
	Vec2 GetScale() const { return m_vScale; }
	CCollider* GetCollider() const { return m_pCollider; }

public:
	void CreateCollider();

	void component_render(HDC _hdc);

public:
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisonExit(CCollider* _pOther);

public:
	virtual void update();
	virtual void final_update() final;
	virtual void render(HDC _hdc);

public:
	CObject();
	virtual ~CObject();
};

