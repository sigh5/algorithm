#pragma once
#include "UI.h"
class CMpBar :
	public CUI
{

public:
	CMpBar();
	virtual ~CMpBar();

public:

	virtual void	initialize_Stream();
	virtual	 void attach_Lisner(std::function<void(void)> lister)override;
	virtual  void Event_Temp()override;
};

