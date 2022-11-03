#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <assert.h>
#include <array>
#include <functional>
using namespace std;

class TestFuntion
{
public:
	TestFuntion(int a):a23(a){}
	TestFuntion(const TestFuntion& rhs) {}
	~TestFuntion() {}


	void Test(std::function<void(TestFuntion*)> m_pq)
	{
		
		if (m_pTest)
			m_pTest = m_pq;

		else
		{

		
		}
	}


public:
	int Add(int a, int b) { return a + b; }
	int Foo() { return 5; }

	void	Set_T(std::function<void(TestFuntion*)> pDynamicCallBack)
	{
		m_pTest = pDynamicCallBack;
		
		bool f = false;
	}

	void Ewqe() { m_pTest(this);  cout << "? ?" << endl; }
	std::function<void(TestFuntion*)> m_pTest = nullptr;

	int a23 = 0;
};


//class TestFoo
//{
//public:
//	TestFoo();
//	~TestFoo();
//
//public:
//	void Foo() {}
//
//
//private:
//	
//
//
//}




int main()
{
	/*std::function<int(TestFuntion&)> m_pFunc = &TestFuntion::Foo;
	cout << m_pFunc(TestFuntion()) << endl;
	
	std::function<int(TestFuntion&, int, int)> m_pFunc2 = &TestFuntion::Add;
	cout << m_pFunc2(TestFuntion(), 10, 20)<<endl;

	std::function<int(TestFuntion*,int,int)> m_pTestFunction = &TestFuntion::Add;
	cout << m_pTestFunction(new TestFuntion(), 10, 10) << endl;*/

	TestFuntion *t = new TestFuntion(2);
	TestFuntion* t2 = new TestFuntion(3);
	
	t->Set_T(
		[&t2](TestFuntion *p)
	{

	});


	t->Ewqe();

	/*std::function<void(TestFuntion*)> as = nullptr;
	t->Test(as);
*/

	

	
	bool b = false;

}