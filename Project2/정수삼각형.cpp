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

int N = 0;

static const int MAX = 501;

array<array<int, MAX>, MAX> arr;

int main()
{
	cin >> N;

	int Num = 0;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j < i+1; ++j)
		{
			cin>> Num;
			arr[i][j] = Num;
		}
	}

	for (int i = N; i >= 1; --i)
	{
		for (int j = 1; j <= i; ++j)
		{
			arr[i - 1][j] += max(arr[i][j], arr[i][j + 1]);
		}
	}

	cout << arr[1][1];

	
}