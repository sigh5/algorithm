#pragma once

#include "PreHeader.h"


class CBase_Item
{
public:
	CBase_Item();
	virtual ~CBase_Item();

public:
	virtual void	initialize_Item() = 0;

	void	Set_Pawn(class	CPawn* pPawn) { m_pPawn = pPawn; }
protected:
	class	CPawn* m_pPawn = nullptr;
	

};

