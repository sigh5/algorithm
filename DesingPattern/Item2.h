#pragma once
#include "Base_Item.h"
class CItem2 :
	public CBase_Item
{
public:
	CItem2();
	virtual ~CItem2();

public:
	virtual void	initialize_Item();
	void			initialize_ItemBool();

	void			initialize_Pointer();

	void			PointerTest(class Cindependent* pTemp);

private:
	void	Item2() { cout << "item2 ÀÔ´Ï´Ù!!" << endl; }
};

