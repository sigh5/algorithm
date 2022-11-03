#pragma once

#include "PreHeader.h"

class CActor;


struct AniamtionFrame
{
	int Frame;
};


class CState abstract
{
public:
	CState(AniamtionFrame InfoAnim , CActor* pActor)  :m_pActor(pActor)
	{ memcpy(&m_InfoAnim, &InfoAnim, sizeof(AniamtionFrame)); }
	
	virtual ~CState() {}

public:
	virtual void Tick(double TimeDelta) = 0;
	virtual void Render() = 0;


protected:
	AniamtionFrame m_InfoAnim;	// 나중에 제로 메모리
	CActor*		  m_pActor = nullptr;

};


class CWalkState final :public CState
{
public:
	CWalkState(AniamtionFrame InfoAnim, CActor* pActor)
	:CState(InfoAnim,pActor)
	{}
	virtual ~CWalkState() {}

public:
	virtual void Tick(double TimeDelta)override;
	virtual void Render() override;
};

class CAttackState final :public CState
{
public:
	CAttackState(AniamtionFrame InfoAnim, CActor* pActor) :CState(InfoAnim, pActor) {}
	virtual ~CAttackState() {}

public:
	virtual void Tick(double TimeDelta)override;
	virtual void Render() override;
};


class CHitState final :public CState
{
public:
	CHitState(AniamtionFrame InfoAnim ,CActor* pActor) :CState(InfoAnim, pActor) {}
	virtual ~CHitState() {}

public:
	virtual void Tick(double TimeDelta)override;
	virtual void Render() override;



};