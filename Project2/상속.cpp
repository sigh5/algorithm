#include <iostream>
using namespace std;



class CBase
{
private:
	int x =0;

public:
	virtual void foo() = 0;
	virtual void foo(int X) { cout << "Base foo(int X)" << endl; }
	virtual void Draw() = 0;

	const int Get_X() { 
		Temp();
		return x; }

private:
	virtual void Temp() { cout << "Base Temp" << endl; }

};

class CDerived : public CBase
{
public:
	virtual void foo() { cout << "CDerived" << endl; }
	virtual void Draw(){ cout << "Derived Draw" << endl; }

private:
	virtual void Temp() { cout << "Derived Temp" << endl; }

};



int main()
{
	CBase* d = new CDerived ;

	//d->CBase::Draw();  // ������ ������ �ȶ����� ������ ������ �ȵ�
	//d->Draw();
	
	d->Get_X();
	delete d;
}
