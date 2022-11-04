#include <iostream>
#include <algorithm>
#include <assert.h>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <array>
#include <memory.h>

using namespace std;

#define MAX 1001

array<int, MAX> dp = { 0 };

int Dynamic_Programing(int num)
{
	if (dp[num] != 0)
		return dp[num];

	return dp[num] = (Dynamic_Programing(num - 1) +
		Dynamic_Programing(num - 2)) %10007;
}

int main()
{
	int n = 0;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	cout << Dynamic_Programing(n) << endl;



}
