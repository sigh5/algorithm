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

const static int Max = 1001;

int N = 0;

array<int, Max> arr;

array<int, Max> dp = {0,};

int MaxNum = 0;


int main()
{
	cin >> N;

	int Num = 0;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Num;
		arr[i] = Num;
	}

	int answer = 0;

	for (int i = 1; i <= N; ++i)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 1; --j)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] +1);
			}
		}
		answer = max(dp[i], answer);
	}



	

	cout << answer;

}