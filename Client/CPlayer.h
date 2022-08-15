#pragma once

#include "CObject.h"

class CTexture;

class CPlayer :
    public CObject
{
private:
    CTexture*       m_pTex;

public:
    virtual void OnCollisionEnter(CCollider* _pOther);
    virtual void OnCollision(CCollider* _pOther);
    virtual void OnCollisonExit(CCollider* _pOther);

public:
    virtual void update();
    virtual void render(HDC _hdc);

public:
    CPlayer();
    ~CPlayer();
};

