#include <iostream>
#include <algorithm>
#include <assert.h>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <array>

using namespace std;

#define MAX 1001

int N = 0, M = 0;

array<array<int,MAX>,MAX> arr;
array<bool, MAX> bVisted = { false };


//
//void dfs(int iStart)
//{
//	if (bVisted[iStart])
//		return;
//	
//	bVisted[iStart] = true;
//
//	size_t vecSize = vec[iStart].size();
//
//	for (size_t i = 0; i < vecSize; ++i)
//	{
//		if (vec[iStart][i] != 0 && !bVisted[vec[iStart][i]])
//		{
//			bVisted[iStart] = true;
//			dfs(vec[iStart][i]);
//		}
//	}
//
//}

void bfs(int iStart)
{
	queue<int> q;
	q.push(iStart);
	bVisted[iStart] = true;

	while (!q.empty())
	{
		int iCurrentFront = q.front();
		q.pop();

		for (int i = 0; i < arr[iCurrentFront].size(); ++i)
		{
			if (arr[iCurrentFront][i] != 0 && !bVisted[arr[iCurrentFront][i]])
			{
				q.push(arr[iCurrentFront][i]);
				bVisted[arr[iCurrentFront][i]] = true;
			}
		}

	}


}


int main()
{
	cin >> N >> M;
	
	
	int iNode1 = 0, iNode2 = 0;


	for (int i = 0; i < M; ++i)
	{
		cin >> iNode1 >> iNode2;

		arr[iNode1][iNode2] = iNode2;
		arr[iNode2][iNode1] = iNode1;
	}
	
	int iCount = 0;
	
	for (int i = 1; i <= N; ++i)
	{
		if (!bVisted[i])
		{
			bfs(i);
			++iCount;
		}
	}

	
	cout << iCount<<endl;



}