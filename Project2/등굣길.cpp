#include <iostream>
#include <string>
#include <list>
#include <array>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int dp[101][101];
int Dir[2] = { 1,-1 };
int answer = 1'000'000'007;



int solution(int m, int n, vector<vector<int>> puddles) {
   

	vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));

	for (int i = 0; i < puddles.size(); ++i)
	{
		dp[puddles[i][1]][puddles[i][0]] = -1;
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (dp[i][j] == -1)
				continue;

			if (dp[i - 1][j] != -1)
				dp[i][j] += dp[i - 1][j];

			if (dp[i][j - 1] != -1)
				dp[i][j] += dp[i][j - 1];

			dp[i][j] %= 1'000'000'007;

		}
	}
	




	return dp[n][m] % 1'000'000'007;
}


int main()
{
	vector<vector<int>> puddles{ { 2, 2} };
	solution(4, 3, puddles);
	return 0;
}