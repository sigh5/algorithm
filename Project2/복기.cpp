#include <iostream>
#include <algorithm>

using namespace std;


class CBase
{
public:
	CBase() { cout << "���̽� ������" << endl; }
	CBase(CBase& rhs) { cout << "���������" << endl; }
	virtual void foo() { cout << "Base" << endl; }

	virtual void Resize() { cout << "Base" << endl; }
	void		boo() { cout << "Base_boo" << endl; }
};

class CDerived : public CBase
{
public:

	virtual void Resize() {

		static_cast<CBase>(*this).Resize(); 
		// ĳ������ ����ϸ� �ӽð�ü�� ������ ȣ���Ѱ���
		// �ʿ���� ���� ������ ȣ��
		// �߸��� ĳ������ ��
		cout << "??" << endl;

	}
	virtual void foo() { cout << "CDerived" << endl; }
	void		 boo() { cout << "CDerived_boo" << endl; }
};

struct A				// ���� ū ���� �������� �ϴϾ� ���δ�.
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
	int* t = *p;	// t�� �ּҰ� *t �� 1
	*p = *q;		// �ּҰ� ��ü     **p�� -1 **q == -1
	*q = t;			// �ּҰ� 1�� �ٲ�  **q == 1
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

	//int i = 1, j = -1;

	//int* Pi = &i;
	//int* Pj = &j;

	////foo(*Pi, *Pj);
	//boo(&Pi, &Pj);

	//cout << *Pi << " " << *Pj;

	CDerived de;
	de.Resize();
}