#include "Boss.h"

#include "HpBar.h"
#include "MpBar.h"

CBoss::CBoss()
{
}


CBoss::~CBoss()
{
}

void CBoss::initialize_Stream()
{
	/*CHpBar* pSour = dynamic_cast<CHpBar*>(m_pUI);
	if (pSour != nullptr)
	{
		m_pUI->attach_Lisner([&]
		{
			Show_HP();
		});
	}

	CMpBar* pDest = dynamic_cast<CMpBar*>(m_pUI);
	if (pDest != nullptr)
	{
		m_pUI->attach_Lisner([&]
		{
			Show_MP();
		});
	}
*/

	for (auto iter : m_pUI)
	{
		CHpBar* pSour = dynamic_cast<CHpBar*>(iter);
		if (pSour != nullptr)
		{
			iter->attach_Lisner([&]
			{
				Show_HP();
			});
		}

		CMpBar* pDest = dynamic_cast<CMpBar*>(iter);
		if (pDest != nullptr)
		{
			iter->attach_Lisner([&]
			{
				Show_MP();
			});
		}

	}

}
//
//void CBoss::Add_Steamer(std::function<void(void)> Steamer)
//{
//	auto& currentSteamer = m_Steamer;
//
//	m_Steamer = [&]
//	{
//		currentSteamer();
//		Steamer();
//	};
//
//}

void CBoss::Show_MP()
{
	cout << "Show_Boss_MP" << endl;
}

void CBoss::Show_HP()
{
	cout << "Show_Boss_HP" << endl;
}
