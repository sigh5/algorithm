#pragma once
#include "Monster_Base.h"
class CBoss :
	public CMonster_Base
{
public:
	CBoss();
	virtual ~CBoss();

public:
	virtual void	initialize_Stream();
	//virtual void	Add_Steamer(std::function<void(void)> Steamer);

	void			Add_List(class CUI* pUI) { m_pUI.push_back(pUI); }


private:
	void	Show_HP();
	void	Show_MP();

};

