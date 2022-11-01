#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;


int T = 0;

int dp[15][15] = { 0, };

int Dp(int K, int N)
{
	if (K < 0 || N < 1)
		return 0;

	if (dp[K][N] == 0)
		return dp[K][N] = Dp(K - 1, N) + Dp(K, N - 1);
	else
		return (dp[K][N]);
}

int main()
{
	cin >> T;

	int K = 0, N = 0;

	for (int i = 1; i < 15; ++i)
	{
		dp[i][1] = 1;
		dp[0][i] = i;
	}

	for (int i = 0; i < T; ++i)
	{
		cin >> K >> N;
		cout << Dp(K, N)<<endl;
	}
	
	return 0;
}