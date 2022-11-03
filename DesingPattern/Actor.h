#pragma once

class CState;

class CActor abstract
{
public:
	CActor() {}
	virtual ~CActor() {}

public:
	virtual void Tick(double TimeDelta) = 0;
	virtual void Render() = 0;

	virtual bool IsHit() { return m_bHit;}
	virtual bool IsAttack() {return m_bAttack;}
	virtual bool IsWalk() { return true; }

	void SetHit() {}


public:
	bool	m_bHit = false;
	bool	m_bAttack = false;

public: 
	void		ChaneState(class CState* pState);

protected:
	CState* m_pState = nullptr;
	
};


class CPlayer final : public CActor
{
public:
	CPlayer() {}
	virtual ~CPlayer() {}
public:
	virtual void Tick(double TimeDelta)override;
	virtual void Render()override;


	



};



class CMonster final : public CActor
{
public:
	virtual void Tick(double TimeDelta)override;
	virtual void Render()override;

	bool		IsAttack();



};