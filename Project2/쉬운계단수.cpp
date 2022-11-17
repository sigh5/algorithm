#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

#define MAX 101
#define DEVIDE 1'000'000'000
long long dp[MAX][10];

int main()
{
	int N = 0;
	cin >> N;

	for (int i = 1; i <= 9; ++i)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][1];
			else if (j == 9)
				dp[i][9] = dp[i - 1][8];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
		
			dp[i][j] %= DEVIDE;
		
		} 
	}

	int Answer = 0;
	for (int i = 0; i <= 9; ++i)
	{
		Answer += dp[N][i];
	}
	cout << Answer;
}