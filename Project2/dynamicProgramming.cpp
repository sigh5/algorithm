#include <iostream>
#include <vector>
#include <algorithm>

// �ٿ��� DP
// ���� ��ȹ��
// �ѹ� �ذ��� ������ �ٽ� Ǯ�� �ʴ°�

// 1.�� ���� ū ������ ���� ������ ���� ���ִ�.
// 2.�� ���� �������� ���� ������ 
//					�װ��� �����ϴ� ū�������� �����ϴ�.

// �Ǻ���ġ ���� ����
// �ð� ���⵵�� -> o(2^n) ���� n���� �پ���

using namespace std;

long long d[100];

long long dp(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 1;
	// 3��° ������ ���ϱ� ���ؼ��� �ڿ��Ͱ� 2��°�ڿ���
	if (d[x] != 0)
		return d[x];
	return d[x]= dp(x - 1) + dp(x - 2);
}

int main()
{
	cout << dp(50);
}


