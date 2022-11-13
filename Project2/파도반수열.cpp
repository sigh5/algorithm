#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <array>
#include <memory.h>

using namespace std;

#define MAX 101

long long dp[MAX] = { 0 ,};


int main()
{
	int iTestNum = 0;

	cin >> iTestNum;

	int iNum = 0;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	int iCount =1;

	for (int i = 0; i < iTestNum; ++i)
	{
		cin >> iNum;
		

		for (int j = 4; j <= iNum; ++j)
		{	
			dp[j] = dp[j - 2] + dp[j - 3];
		}

		
		cout << dp[iNum] << endl;
	}


}