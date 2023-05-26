#include <iostream>
#include <algorithm>

using namespace std;


class CBase
{
public:
	virtual void foo() { cout << "Base" << endl; }
	void		boo() { cout << "Base_boo" << endl; }
};

class CDerived : public CBase
{
public:
	virtual void foo() { cout << "CDerived" << endl; }
	void		 boo() { cout << "CDerived_boo" << endl; }
};

struct A				// 가장 큰 값을 기준으로 하니씩 쌓인다.
{
	char _a;		// 8
	double _b;		// 8
	int		_c;     
	short	_d;
	float   _f;
};

struct B
{
	A _a;
	bool b;
};

void foo(int& p, int& q)
{
	int* t = &p;
	p = q;
	q = *t;
	p = 3;
}

void boo(int** p, int** q)
{
	int* t = *p;	// t는 주소값 *t 는 1
	*p = *q;		// 주소값 교체     **p는 -1 **q == -1
	*q = t;			// 주소값 1로 바뀜  **q == 1
	**p = 3;        // **p  ==3 
}



int main()
{
	/*CDerived* derived = new CDerived();
	CBase* Base = dynamic_cast<CBase*>(derived);
	
	derived->foo();
	Base->foo();

	derived->boo();
	Base->boo();*/

	int i = 1, j = -1;

	int* Pi = &i;
	int* Pj = &j;

	//foo(*Pi, *Pj);
	boo(&Pi, &Pj);

	cout << *Pi << " " << *Pj;


}