#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <Windows.h>

using namespace std;

// �޸������̼�(memoization)
int cache[50][50];


int combination(int n, int r)
{
	//���� ���
	if (r == 0 || n == r)
		return 1;

	// �̹� ���� ������ ������ �ٷι�ȯ
	int &ret = cache[n][r];
	if (ret != -1)
		return ret;


	// ���� ���� ���ؼ� ĳ�ÿ� ����
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