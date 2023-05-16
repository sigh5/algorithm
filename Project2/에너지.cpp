#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <set>


using namespace std;

#define MAX_NUM 11

int N = 0;





int iMaxResult = -100'000'000;


void dfs(vector<int> Vec, int iResult) // 값복사해야돼 원본데이터를 수정하면안되는데
{
	size_t VecSize = Vec.size();

	if (VecSize == 2)
	{
		iMaxResult = max(iResult, iMaxResult);
		return;
	}

	for (size_t i = 1; i < VecSize-1; ++i)
	{
		vector<int> temp = Vec;
		temp.erase(temp.begin() + i);
		dfs(temp, Vec[i - 1] * Vec[i + 1] + iResult);
	}
	
}


int main()
{
	cin >> N;


	vector<int> NumVec( N );

	for (int i = 0; i < N; ++i)
	{
		cin >> NumVec[i];
	}

	dfs(NumVec, 0);


	cout << iMaxResult;
}