//#include <iostream>
//#include <algorithm>
//#include <assert.h>
//#include <vector>
//#include <queue>
//#include <string>
//#include <unordered_map>
//
//using namespace std;
//
//#define PURE	0
//
//// State ∆–≈œ
//
//class State abstract 
//{
//public:
//	State() {}
//	virtual ~State() {}
//
//public:
//	virtual void Update(float fTimeDelta) = PURE;
//};
//
//class RunState : public State
//{
//public:
//	RunState() {}
//	virtual ~RunState() {}
//
//public:
//	virtual void Update(float fTimeDelta) override
//	{
//		cout << "Run_State!! " << endl;
//	}
//};
//
//class JumpState : public State
//{
//public:
//	JumpState() {}
//	virtual ~JumpState() {}
//
//public:
//	virtual void Update(float fTimeDelta) override
//	{
//		cout << "Jump_State!! " << endl;
//	}
//};
//
//class CObj abstract
//{
//public:
//	virtual void	Update(float fTimeDelta) = 0;
//	virtual void	Set_State(State* CurrentState) = 0;
//};
//
//class CNull_Obj final : public CObj
//{
//public:
//	virtual void	Update(float fTimeDelta) {}
//	virtual void	Set_State(State* CurrentState) {}
//};
//
//
//class CPlayer :public CObj
//{
//public:
//	virtual void Update(float fTimeDelta) override
//	{
//		pCurrentState->Update(fTimeDelta);
//	}
//
//	virtual void	Set_State(State* CurrentState) override
//	{
//		pCurrentState = decltype(CurrentState)(CurrentState);
//	}
//
//private:
//	State* pCurrentState = nullptr;
//};
//
//int main()
//{
//	CObj* pPlayer = new CPlayer;
//
//	if (pPlayer != nullptr)
//	{
//		JumpState* pRun = new JumpState;
//
//		pPlayer->Set_State(pRun);
//		pPlayer->Update(1.f);
//	}
//
//
//
//
//	delete pPlayer;
//	pPlayer = nullptr;
//
//	//delete pRun;
//	pRun = nullptr;
//}
//
//
