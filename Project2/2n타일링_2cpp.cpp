#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <array>
#include <memory.h>

using namespace std;

#define  MAX 1000

array<long long, MAX> dp;


int main()
{
	int N = 0;
	cin >> N;

	dp[0] = 1;
	dp[1] = 3;

	for (int i = 2; i < N; ++i)
	{
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) %10007;
	}

	long long iResult = dp[N-1];

	cout << iResult << '\n';
}