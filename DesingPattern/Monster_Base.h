#pragma once

#include "PreHeader.h"

class CMonster_Base
{
public:
	CMonster_Base();
	virtual ~CMonster_Base();

public:
	virtual void	initialize_Stream() = 0;
	//virtual void	Add_Steamer(std::function<void(void)> Steamer) = 0;


protected:
	//std::function<void(void)> m_Steamer = [] {};
	list<class CUI*>	m_pUI;
};

