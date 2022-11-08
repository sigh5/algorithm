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

#define MAX 301

array<int, MAX> iStairs;

array<int ,MAX> dp;

int N = 0;



int main()
{
	cin >> N;

	int iNum = 0;

	iStairs[0] = 0;
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> iNum;
		iStairs[i] = iNum;
	}
	dp[1] = iStairs[1];
	dp[2] = iStairs[1] + iStairs[2];

	for (int i = 3; i <= N; ++i)
	{
		dp[i] = max(dp[i - 3] + iStairs[i] + iStairs[i - 1], dp[i - 2] + iStairs[i]);
	}

	cout << dp[N];

}