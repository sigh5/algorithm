#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <array>

using namespace std;

#define MAX 30

array<array<long long, MAX>, MAX> dp = {0,};

long long Solve(int M, int N)
{
	if (dp[N][M]!=0)
		return dp[N][M];

	if (N == 0 || M == 0)
		return dp[M][N] = 1;

	return dp[M][N] = Solve(M - 1, N - 1) + Solve(M - 1, N);

}



int main()
{
	int iTestNum = 0;
	int N = 0, M = 0;

	cin >> iTestNum;

	for (int i = 0; i < iTestNum; ++i)
	{
		cin >> N >> M;
		cout << Solve(M, N) << endl;
	}





}