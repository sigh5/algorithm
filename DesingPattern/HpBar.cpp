#include "HpBar.h"
#include "Pawn.h"


CHpBar::CHpBar()
{
}


CHpBar::~CHpBar()
{
}


void CHpBar::attach_Lisner(std::function<void(void)> lister)
{
	m_listner = lister;
}

void CHpBar::Event_Temp()
{
	m_listner();
}
