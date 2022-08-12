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


#define DT CTimeMgr::GetInst()->GetDeltaTime()
#define fDT CTimeMgr::GetInst()->GetFDeltaTime()

