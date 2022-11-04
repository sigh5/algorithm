#pragma once
#include "Base_Item.h"

class CItem1 :
	public CBase_Item
{
public:
	CItem1();
	virtual ~CItem1();

public:
	virtual void	initialize_Item();

	virtual void	initialize_ItemBool();

	void			initialize_Pointer();

	void			PointerTest(class Cindependent* pTemp);

private:
	void	Item1() { cout << "item1 ÀÔ´Ï´Ù!!" << endl; }
};

