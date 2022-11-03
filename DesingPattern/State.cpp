#include "State.h"
#include "Actor.h"

void CWalkState::Tick(double TimeDelta)
{
	if (m_pActor->IsWalk())
	{
		for (int i = 0; i < m_InfoAnim.Frame; ++i)
		{
			cout << " �ȱ� �ִϸ��̼�" << i << endl;
		}
	}
}

void CWalkState::Render()
{
}

void CAttackState::Tick(double TimeDelta)
{
	if (m_pActor->IsAttack())
	{
		for (int i = 0; i < m_InfoAnim.Frame; ++i)
		{
			cout << " ���� �ִϸ��̼�" << i << endl;
		}
	}
}

void CAttackState::Render()
{
}

void CHitState::Tick(double TimeDelta)
{
	if (m_pActor->IsHit())
	{
		for (int i = 0; i < m_InfoAnim.Frame; ++i)
		{
			cout << " �ĸ´� �ִϸ��̼�" << i << endl;
		}
	}
}

void CHitState::Render()
{

}
