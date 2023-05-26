#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>

using namespace std;




vector<int> Solution(vector<int> InputVec)
{
	vector<int> Answer{ InputVec };
	//// 1번 std::set 을 사용하는 방법
	//set<int> UniqueSortSet;
	//for (auto InputData : InputVec)
	//{
	//	UniqueSortSet.insert(InputData);
	//}
	//for (auto UniqueData : UniqueSortSet)
	//{
	//	Answer.push_back(UniqueData);
	//}

	// 2번 
	sort(Answer.begin(), Answer.end());
	Answer.erase(unique(Answer.begin(), Answer.end()), Answer.end());
	return Answer;
}



int main()
{
	//unsigned int demical = 10;
	//const int bitNum = 16;
	//bitset<bitNum> bit{ demical };


	//cout << bit.to_string() << endl;

	//cout << bit[3] <<endl;

	vector<int> InputData{ 5,5,4,3,2,1,1,3 };
	for (auto Result_Data : Solution(InputData))
	{
		cout << Result_Data << " ";
	}
	
	puts("");

	vector<int> DataVec{ 5,4,3,2,1,10,11 };

	sort(DataVec.begin(), DataVec.end());
	int FindData = 5;
	


	if (std::binary_search(DataVec.begin(), DataVec.end(), FindData))
		cout << "있음";


	bool c = false;
	return 0;
}