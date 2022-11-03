#include <iostream>

#include "State.h"
#include "StrategyPattern.h"
#include "Actor.h"
int main()
{
	//// strategyPattern_Demo
	//Hard_AI* pAI = new Hard_AI;
	//ComPlayer* pComPlayer = new ComPlayer(pAI);
	//pComPlayer->ComPlayerThink();

	CPlayer* pPlayer = new CPlayer;
	
	// 이건 init에 넣으면되고
	AniamtionFrame InfoAnim;
	memset(&InfoAnim, 0, sizeof(AniamtionFrame));
	InfoAnim.Frame = 5;
	// 이건 init에 넣으면되고
	CHitState *pHitState = new CHitState(InfoAnim,pPlayer);
	
	InfoAnim;
	memset(&InfoAnim, 0, sizeof(AniamtionFrame));
	InfoAnim.Frame = 10;
	CAttackState *pAttackState = new CAttackState(InfoAnim, pPlayer);

	
	
	
	while (true)
	{
		int i = 0; 
		cin >> i;

		if (i == 3)
			break;
		else if (i == 1)
		{
			pPlayer->m_bAttack = false;
			pPlayer->m_bHit = true;
			pPlayer->ChaneState(pHitState);
			
		}
		else if (i == 2)
		{
			pPlayer->m_bHit = false;
			pPlayer->m_bAttack = true;
			pPlayer->ChaneState(pAttackState);
			
		}
	
		pPlayer->Tick(1.f);
	}

	
	
	delete pHitState;
	delete pAttackState;
	delete pPlayer;
	



}