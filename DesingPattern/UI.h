#pragma once

#include "PreHeader.h"

class CUI
{
public:
	CUI();
	virtual ~CUI();

public:
	virtual	 void attach_Lisner(std::function<void(void)> lister) = 0;
	virtual  void Event_Temp() = 0;


	

protected:
	std::function<void(void)> m_listner = [] {};

	//class	CPawn* m_pPawn = nullptr;
	//void	Set_Pawn(class	CPawn* pPawn) { m_pPawn = pPawn; }


};

