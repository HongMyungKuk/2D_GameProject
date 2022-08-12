#pragma once

class CTimeMgr
{
	SINGLE(CTimeMgr);

private:
	LARGE_INTEGER		m_llPrevCount;
	LARGE_INTEGER		m_llCurCount;
	LARGE_INTEGER		m_llFrequency;

	double				m_dDT;
	double				m_dAccTime;
	int					m_iFPS;

public:
	double GetDeltaTime() const { return m_dDT; }
	float GetFDeltaTime() const { return (float)m_dDT; }

public:
	void init();
	void update();
	void render();
};

