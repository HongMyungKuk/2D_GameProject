#pragma once

class CObject;

class CCollider
{
private:
	CObject*		m_pOwner;
	Vec2			m_vFinalPos;
	Vec2			m_vScale;
	Vec2			m_vOffSet;

	static UINT		s_iID;
	UINT			m_iID;

	bool			m_bFlag;

public:
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	void SetOffSet(Vec2 _vOffSet) { m_vOffSet = m_vOffSet; }

	Vec2 GetScale() const { return m_vScale; }
	Vec2 GetFinalPos() const { return m_vFinalPos; }
	UINT GetID() const { return m_iID; }

public:
	void OnCollisionEnter(CCollider* _pOther);
	void OnCollision(CCollider* _pOther);
	void OnCollisionExit(CCollider* _pOther);

public:
	void final_update();
	void render(HDC _hdc);

public:
	CCollider();
	CCollider(const CCollider& _copy);
	~CCollider();

	friend class CObject;
};

