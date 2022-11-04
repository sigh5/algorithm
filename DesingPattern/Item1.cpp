#include "Item1.h"

#include "Pawn.h"

CItem1::CItem1()
{
}


CItem1::~CItem1()
{
}

void CItem1::initialize_Item()
{
	m_pPawn->AttachListner([&]() {

		Item1();
	});
}

void CItem1::initialize_ItemBool()
{
	m_pPawn->AttachListner2([&](bool b) {
		
		if(b==true)
			Item1();
	});

}

void CItem1::initialize_Pointer()
{
	m_pPawn->AttachListner3(
		[this](Cindependent *pCom)
	{
		PointerTest(pCom);
	});
}

void CItem1::PointerTest(Cindependent * pTemp)
{
		cout << "ÀÌ°Ç°¡?1 !!" << endl;
}

//void CItem1::initialize_PonterTest()
//{
//	m_pPawn->AttachListner2([&](bool b) {
//
//		if (b == true)
//			Item1();
//	});
//
//}