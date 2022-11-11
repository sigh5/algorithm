#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

#define  MAX		100001

int dp[MAX] = { 0, };
int arr[MAX] = { 0, };

int main()
{
	int N = 0;
	cin >> N;

	int num = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		arr[i] = num;
		dp[i] = arr[i];
	}

	dp[0] = arr[0];

	int iMax = dp[0];

	for (int i = 1; i < N; ++i)
	{
		dp[i] = max(dp[i], dp[i - 1] + arr[i]);
		
		
		iMax = max(dp[i], iMax);
	
	}

	cout << iMax << endl;




}