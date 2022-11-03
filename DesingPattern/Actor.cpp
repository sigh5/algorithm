#include "Actor.h"
#include "PreHeader.h"
#include "State.h"

void CActor::ChaneState(CState * pState)
{
	if (nullptr == pState)
		return;

	//delete m_pState;
	
	m_pState = pState;
}

void CPlayer::Tick(double TimeDelta)
{
	m_pState->Tick(TimeDelta);

}

void CPlayer::Render()
{
	m_pState->Render();
}

void CMonster::Tick(double TimeDelta)
{
	m_pState->Tick(TimeDelta);
}

void CMonster::Render()
{
	m_pState->Render();
}

bool CMonster::IsAttack()
{
	return true;
}
