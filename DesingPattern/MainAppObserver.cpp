#include "PreHeader.h"

#include "TitleScene.h"
#include "Button.h"


int main()
{
	CMyButton* pMyButton = new CMyButton();
	CTitleScene* pScene = new CTitleScene();

	pScene->m_pStartbutton = pMyButton;
	pScene->initialize();

	while (true)
	{
		int i = 0;
		cin >> i;

		if (i == 0)
		{
			pMyButton->Click();
		}
	}

	delete pMyButton;
	pMyButton = nullptr;

	delete pScene;
	pScene = nullptr;
}