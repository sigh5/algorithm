#include "PreHeader.h"

#include "Boss.h"
#include "HpBar.h"
#include "MpBar.h"
#include "Item1.h"
#include "Item2.h"
#include "Item3.h"

#include "Pawn.h"
#include "Cindependent.h"

int main()
{
	/*CBoss* pBoss = new CBoss();

	CHpBar* pHpBar = new CHpBar();
	CMpBar* pMpBar = new CMpBar();

	pBoss->Add_List(pHpBar);
	pBoss->Add_List(pMpBar);

	pBoss->initialize_Stream();

	while (true)
	{
		int iNum = 0;

		cin >> iNum;

		if (iNum == 0)
		{
			pHpBar->Event_Temp();
		}
		else if (iNum == 1)
		{
			pMpBar->Event_Temp();
		}


	}*/

	Cindependent* pTemp = new Cindependent;
	CPawn* pPawn = new CPawn;
	CItem1* pItem1 = new CItem1;
	CItem2* pItem2 = new CItem2;
	CItem3* pItem3 = new CItem3;
	
	


	pItem1->Set_Pawn(pPawn);
	pItem1->initialize_Item();
	pItem1->initialize_ItemBool();
	pItem1->initialize_Pointer();


	pItem2->Set_Pawn(pPawn);
	pItem2->initialize_Item();
	pItem2->initialize_ItemBool();
	pItem2->initialize_Pointer();

	pItem3->Set_Pawn(pPawn);
	pItem3->initialize_Item();
	pItem3->initialize_ItemBool();
	pItem3->initialize_Pointer();
	



	while (1)
	{
		int iNum = 0;

		cout << "0 : 입력 이벤트 발생  그외 미발생"<<endl;
		                                                                                                                                                                                                                                                               
		cin >> iNum;
		if (iNum == 0)
		{
			
			//pPawn->ItemTest();
			//pPawn->boolTest(false);
			pPawn->Pointer_Test2(pTemp);
		}
		
		if (iNum == 1)
		{
			//pPawn->ItemTest();
			//pPawn->boolTest(true);
		}

	}







}