#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

enum Toss { A, B,C};
enum class Tass {A,B,C };
enum class TT{A,B,C};


void foo(int* a);
void foo(const int* a);

void foo(int* a)
{

}

void foo(const int* a)
{

}

enum bitSetBool
{
	BIT_SET_FALSE, BIT_SET_TRUE, BIT_SET_END,
};

int main()
{
	vector<int> temp{ 1,2,3,4,5,6 };

	//temp.erase(temp.begin());
	remove(temp.begin(),temp.end(),1);

	for (auto num : temp)
	{
		cout << num << endl;
	}

	cout << "capacity" << temp.capacity() << "  size" << temp.size();
	

	const int aw= 1;
	int bw = 0;
	foo(&aw);
	foo(&bw);
	
	vector<bitset<1>> boolVec;

	boolVec.push_back(BIT_SET_FALSE);
	boolVec.push_back(BIT_SET_TRUE);
	boolVec.push_back(BIT_SET_FALSE);

	bool b = false;


	return 0;
}