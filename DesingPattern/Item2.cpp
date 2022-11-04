#include "Item2.h"
#include "Pawn.h"

CItem2::CItem2()
{
}


CItem2::~CItem2()
{
}

void CItem2::initialize_Item()
{
	m_pPawn->AttachListner([&] {
	
			Item2();
	});

}

void CItem2::initialize_ItemBool()
{
	m_pPawn->AttachListner2([&](bool b) {

		if (b == true)
			Item2();
	});

}

void CItem2::initialize_Pointer()
{
	m_pPawn->AttachListner3(
		[this](Cindependent *pCom)
	{
		PointerTest(pCom);
	});
}

void CItem2::PointerTest(Cindependent * pTemp)
{
	cout << "ÀÌ°Ç°¡2?" << endl;
}
