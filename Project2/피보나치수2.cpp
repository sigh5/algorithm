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

#define MAX 91

long long dp[MAX];

long long dynamic_Programinc(int N)
{
	if (N == 0)
		return 0;

	if (N <= 2)
		return 1;


	if (dp[N] != 0)
		return dp[N];

	return dp[N] = dynamic_Programinc(N - 1) + dynamic_Programinc(N - 2);

}


int main()
{
	int Num = 0;

	cin >> Num;

	cout << dynamic_Programinc(Num);


}