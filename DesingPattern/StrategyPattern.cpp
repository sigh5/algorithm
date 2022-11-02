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
	virtual void Think()override { cout << "초급 알고리즘" << endl; }
};

class Normal_AI final : public AI
{
public:
	Normal_AI() {}
	virtual ~Normal_AI() {}

public:
	virtual void Think() override { cout << "중급 알고리즘" << endl; }
};

class Hard_AI final : public AI
{
public:
	Hard_AI() {}
	virtual ~Hard_AI() {}

public:
	virtual void Think()override { cout << "고급 알고리즘" << endl; }
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
	AI*		m_pAI = nullptr;	// 실제 프로젝트에서 컴포넌트 객체로 만들기
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
			cout << "초급 알고리즘" << endl;
			break;

		case AI_LEVEL::NORMAL:
			cout << "중급 알고리즘" << endl;
			break;

		case AI_LEVEL::HARD:
			cout << "고급 알고리즘" << endl;
			break;
		default:
			assert(m_eLevel == AI_LEVEL::END && "값이 제대로 안들어감");
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