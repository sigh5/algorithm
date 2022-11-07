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

#define MAX 1001
#define INF 1001

int N = 0;

int arr[MAX][3];
array<int, 3> cost = { 0 };


int main()
{
	cin >> N;

	arr[0][0] = 0;
	arr[0][1] = 0;
	arr[0][2] = 0;

	int iRGB = 0;

	for (int i = 1; i <= N; ++i)
	{
		cin >> cost[0] >> cost[1] >> cost[2];

		arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + cost[0];
		arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + cost[1];
		arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + cost[2];
	}
	
	cout << min(arr[N][0], min(arr[N][1], arr[N][2])) << endl;

}