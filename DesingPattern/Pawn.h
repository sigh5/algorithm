#pragma once

#include "PreHeader.h"
#include "Cindependent.h"


class CPawn
{
public:
	CPawn();
	~CPawn();

public:
	/*
	void	ItemTest() { m_lister(); }
	void	boolTest(bool b) { m_lister2(b); }
	void	PointerTest(Cindependent* pPointer) { m_lister3(pPointer); }

	void	Pointer_Test2(Cindependent* pPointer)
	{
		for (auto iter : m_lister4)
			iter(pPointer);
	}

	void	AttachListner(std::function<void(void)> listner)
	{
		// 다중의 구독자를 가질 수 있게만드는거야 
		const auto& current = m_lister;
		m_lister = [=]
		{
			current();
			listner();
		};
	}
	void	AttachListner2(std::function<void(bool)> listner)
	{
		const auto& current = m_lister2;
		m_lister2 = [=](bool b)
		{
			current(b);
			listner(b);
		};
	}

	void AttachListner3(std::function<void(Cindependent*)> listner)
	{
		m_lister4.push_back(listner);
	}

	이걸 관리하는 매니져를 만들어야됌

	*/
private:
	std::function<void(void)> m_lister = [] {};
	std::function<void(bool)> m_lister2 = [](bool b=false) {};

	std::function<void(Cindependent*)> m_lister3 =nullptr;
	
	list<std::function<void(Cindependent*)>> m_lister4;


	Cindependent*	pTemp = nullptr;

	//std::function<void(bool)> m_lister2 = [](bool b = false) {};

};

