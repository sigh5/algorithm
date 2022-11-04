#pragma once

#include "PreHeader.h"
#include "Button.h"


class CTitleScene
{
public:
	CTitleScene();
	~CTitleScene();

public:
	void	initialize() 
	{
		m_pStartbutton->attachLister([&] 
		{ 
			Test();
		});
	}

	void	AttachListner(std::function<void(void)> listner)
	{ 
		const auto& current = m_listner;

		m_listner = [=]
		{
			current();
			listner(); 
		};
	
	}
	void Click()
	{
		m_listner();
	}

	void Test()
	{
		cout << "아 이제알았다!" << endl;
	}

public:
	CMyButton* m_pStartbutton = nullptr;

public:
	std::function<void(void)> m_listner = [] {};
	

};

