#include <iostream>

using namespace std;

#define MAX 30

static long long dp[MAX][MAX] = {0,};


long long Combination(int M, int N)
{
	if (dp[M][N] != 0)
		return dp[M][N];

	if (N == 0 || M == N)
	{
		(dp[M][N] = 1);
		return dp[M][N];
	}
	dp[M][N] = Combination(M - 1, N-1) + Combination(M - 1, N);

	return dp[M][N];
}



int main()
{
	int iTestNum = 0;
	int N = 0, M = 0;

	cin >> iTestNum;

	for (int i = 0; i < iTestNum; ++i)
	{
		cin >> N >> M;
	
		printf("%d \n" ,Combination(M, N));
	}





}