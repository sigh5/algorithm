#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <memory.h>
#include <stack>
#include <string>
#include <array>

using namespace std;

int dp[12] = { 0,1,2,4,0 };

void Dp()
{
	int Num = 4;

	while (Num < 12)
	{
		dp[Num] = dp[Num - 3] + dp[Num - 2] + dp[Num - 1];
		++Num;
	}

	
}


int main()
{
	int T = 0;
	cin >> T;

	Dp();
	int Num = 0;
	for (int i = 0; i < T; ++i)
	{
		cin >> Num;
		cout << dp[Num] <<endl;
	}

}