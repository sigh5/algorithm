#pragma once
#include "PreHeader.h"

class CMyButton
{
public:
	CMyButton();
	~CMyButton();

public:
	void		 Stream_Listener(std::function<void(void)> listner);
	virtual void Click();


private:
	std::function<void(void)> listner = []{};

};

