#pragma once

#include "CRes.h"

class CTexture :
    public CRes
{
private:
    HDC         m_hdc;
    HBITMAP     m_hBitmap;
    BITMAP      m_tBitInfo;

public:
    HDC GetDC() const { return m_hdc; }
    int Height() const { return m_tBitInfo.bmHeight; }
    int Width() const { return m_tBitInfo.bmWidth; }

public:
    void Load(const wstring& _strPath);

public:
    CTexture();
    ~CTexture();
};

