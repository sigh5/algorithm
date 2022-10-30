#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <Windows.h>

using namespace std;

// 메모이제이션(memoization)
int cache[50][50];


int combination(int n, int r)
{
	//기저 사례
	if (r == 0 || n == r)
		return 1;

	// 이미 답을 구한적 있으면 바로반환
	int &ret = cache[n][r];
	if (ret != -1)
		return ret;


	// 새로 답을 구해서 캐시에 저장
	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}


int main()
{
	::memset(cache, -1, sizeof(cache));
	__int64 start = GetTickCount64();

	int lotto = combination(45, 6);

	__int64 End = GetTickCount64();

	cout << End - start << "ms" << endl;

}