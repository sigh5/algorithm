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

const static int MAX = 10001;

int dp[MAX] = { 0, };
int iWine[MAX] = { 0 };


int main()
{
	int N = 0;

	cin >> N;
	int iNum = 0;

	for (int i = 1; i <= N; ++i)
	{
		cin >> iNum;
		iWine[i] = iNum;
		
	}

	int iMaxSum = 0;
	dp[1] = iWine[1];
	dp[2] = iWine[2] +dp[1];

	iMaxSum = dp[2];

	for (int i = 3; i <= N; ++i)
	{
	
		dp[i] = max(dp[i - 3] + iWine[i] + iWine[i - 1], max(dp[i - 1], dp[i - 2] + iWine[i]));	
	}


	cout << dp[N];


}

