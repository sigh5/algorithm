#include "MpBar.h"



CMpBar::CMpBar()
{
}


CMpBar::~CMpBar()
{
}

void CMpBar::initialize_Stream()
{
}

void CMpBar::attach_Lisner(std::function<void(void)> lister)
{
	m_listner = lister;
}

void CMpBar::Event_Temp()
{
	m_listner();
}
