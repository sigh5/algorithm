#include <iostream>
#include <algorithm>
#include <assert.h>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <array>

using namespace std;

#define MAX		41

int iCallZero=0;
int iCallOne=0;
array<unsigned int, MAX> dp = {0};

vector<pair<int, int>> vec;

unsigned int DynamicProgramming(int Num)
{
	if (Num == 0)
		return 0;

	if (Num == 1)
		return 1;

	if (dp[Num] != 0)
	{	
		return dp[Num];
	}

	int a= dp[Num] = DynamicProgramming(Num-1) + DynamicProgramming(Num - 2);

	vec[Num].first = vec[Num - 1].first + vec[Num - 2].first;
	vec[Num].second = vec[Num - 1].second + vec[Num - 2].second;
	
	return a;
}




int main()
{
	int iTestCase = 0;
	
	cin >> iTestCase;
	
	vec.resize(MAX, {0,0});

	dp[0] = 0;
	dp[1] = 1;

	vec[0] = { 1,0 };
	vec[1] = { 0,1 };

	int iInputNum = 0;

	for (int i = 0; i < iTestCase; ++i)
	{
		cin >> iInputNum;
		DynamicProgramming(iInputNum);
		cout << vec[iInputNum].first << " " << vec[iInputNum].second << endl;
		
	}


}