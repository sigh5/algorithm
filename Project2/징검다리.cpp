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

	dynamic_cast<CDerived*>(Base)->Temp();		// ���� ��ü Ÿ���̸� dynamic_cast ���� �ٿ� ĳ������ �Ļ���ü�� ���� x
												// abort has been call �� ��ϴ�.
	
}
