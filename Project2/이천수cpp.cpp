#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

#define MAX 91

long long dp[MAX] ;




int main()
{
	int N = 0;
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	


	for (int i = 3; i <= N; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[N];


}
