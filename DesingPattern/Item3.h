#pragma once
#include "Base_Item.h"

class CItem3 final :public CBase_Item
{
public:
	CItem3();
	virtual ~CItem3();

public:
	virtual void	initialize_Item();
	void			initialize_ItemBool();
	void			initialize_Pointer();

	void			PointerTest(class Cindependent* pTemp);

private:
	void	Item3() { cout << "item3 ÀÔ´Ï´Ù!!" << endl; }
};



