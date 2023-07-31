#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	std::vector<int> Temp{ 1,2,3,4 };

	std::vector<int> Sour{ 1,2 };

	cout <<"Prev Erase Temp Size : " << Temp.size() << endl;
	cout << "Prev Erase Temp Capacity : " << Temp.capacity() << endl;
	Temp.erase(Temp.begin());
	cout << "After Erase Temp Size : " << Temp.size() << endl;
	cout << "Prev Erase Temp Capacity : " << Temp.capacity() << endl;

	puts("_______________________");

	cout << "Prev Erase Sour Size : " << Sour.size() << endl;
	cout << "Prev Erase Sour Capacity : " << Sour.capacity() << endl;
	remove(Sour.begin(),Sour.end(),1);
	cout << "After Erase Sour Size : " << Sour.size() << endl;
	cout << "Prev Erase Sour Capacity : " << Sour.capacity() << endl;




}