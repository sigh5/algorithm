#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class CBase
{
public:
	virtual void Temp() { cout << "Base" << endl; }
	virtual ~CBase() {}
};

class CDerived : public CBase
{
public:
	virtual ~CDerived() {}
	virtual void Temp() { cout << "CDerived" << endl; }
};


int main()
{
	CBase* Base = new CDerived;

	dynamic_cast<CDerived*>(Base)->Temp();		// 같은 객체 타입이면 dynamic_cast 적용 다운 캐스팅한 파생객체면 적용 x
												// abort has been call 이 뜹니다.
	
}
