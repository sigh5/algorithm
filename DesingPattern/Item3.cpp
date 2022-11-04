#include "Item3.h"

#include "Pawn.h"
#include "Cindependent.h"

CItem3::CItem3()
{
}


CItem3::~CItem3()
{
}

void CItem3::initialize_Item()
{

	m_pPawn->AttachListner([&] {

		Item3();
	});
}

void CItem3::initialize_ItemBool()
{
	m_pPawn->AttachListner2([&](bool b) {

		if (b == true)
			Item3();
	});
}

void CItem3::initialize_Pointer()
{
	 m_pPawn->AttachListner3(
		[this](Cindependent *pCom)
	{
		PointerTest(pCom);
	});

}

void CItem3::PointerTest(Cindependent * pTemp)
{
	cout << "ÀÌ°Ç°¡3?" << endl;
}
