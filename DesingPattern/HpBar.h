#pragma once
#include "UI.h"
class CHpBar :
	public CUI
{
public:
	CHpBar();
	virtual ~CHpBar();


	virtual	 void attach_Lisner(std::function<void(void)> lister)override;
	virtual  void Event_Temp()override;




};

