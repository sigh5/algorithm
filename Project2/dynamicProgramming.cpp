#include <iostream>
#include <vector>
#include <algorithm>

// 줄여서 DP
// 동적 계획법
// 한번 해결한 문제는 다시 풀지 않는것

// 1.번 가정 큰 문제를 작은 문제로 나눌 수있다.
// 2.번 작은 문제에서 구한 정답은 
//					그것을 포함하는 큰문제에서 동일하다.

// 피보나치 수열 기준
// 시간 복잡도가 -> o(2^n) 에서 n으로 줄어든다

using namespace std;

long long d[100];

long long dp(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 1;
	// 3번째 수열을 더하기 위해서는 뒤에것과 2번째뒤에것
	if (d[x] != 0)
		return d[x];
	return d[x]= dp(x - 1) + dp(x - 2);
}

int main()
{
	cout << dp(50);
}


