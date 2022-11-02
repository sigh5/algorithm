#include <iostream>
#include <vector>
#include <assert.h>
#include <queue>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

class AI abstract
{
public:
	AI() {}
	virtual ~AI() {}

public:
	virtual void Think() = 0;

};

class Easy_AI final :public AI
{
public:
	Easy_AI() {}
	virtual ~Easy_AI() {}

public:
	virtual void Think()override { cout << "�ʱ� �˰���" << endl; }
};

class Normal_AI final : public AI
{
public:
	Normal_AI() {}
	virtual ~Normal_AI() {}

public:
	virtual void Think() override { cout << "�߱� �˰���" << endl; }
};

class Hard_AI final : public AI
{
public:
	Hard_AI() {}
	virtual ~Hard_AI() {}

public:
	virtual void Think()override { cout << "��� �˰���" << endl; }
};


class ComPlayer
{
public:
	ComPlayer(AI* pAI) 
		:m_pAI(pAI) { }
	~ComPlayer() {}

public:
	void ComPlayerThink() { m_pAI->Think(); }

private:
	AI*		m_pAI = nullptr;	// ���� ������Ʈ���� ������Ʈ ��ü�� �����
};

// notUse strategyPattern

enum class AI_LEVEL {EASY, NORMAL ,HARD, END};

class ComPlayerNotUse
{
	

public:
	ComPlayerNotUse(AI_LEVEL eAI)
		:m_eLevel (eAI){}
	~ComPlayerNotUse() {}

public:
	void ComPlayerThink()
	{
		switch (m_eLevel)
		{
		case AI_LEVEL::EASY:
			cout << "�ʱ� �˰���" << endl;
			break;

		case AI_LEVEL::NORMAL:
			cout << "�߱� �˰���" << endl;
			break;

		case AI_LEVEL::HARD:
			cout << "��� �˰���" << endl;
			break;
		default:
			assert(m_eLevel == AI_LEVEL::END && "���� ����� �ȵ�");
			break;
		}
	}

private:
	AI_LEVEL	m_eLevel = AI_LEVEL::END;
};





int main()
{
	
	// strategyPattern_Demo
	Hard_AI* pAI = new Hard_AI;
	ComPlayer* pComPlayer = new ComPlayer(pAI);
	pComPlayer->ComPlayerThink();


}