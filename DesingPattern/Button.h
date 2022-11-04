#pragma once

#include "PreHeader.h"


class CMyButton
{
public:
	CMyButton() {}
	~CMyButton() {}

public:
	void attachLister(std::function<void(void)> listner) { m_listner = listner; }
	void Click() { m_listner(); }

protected:
	std::function<void(void)> m_listner = [] {};

};