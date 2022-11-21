#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <memory.h>
#include <array>

using namespace std;

#define MAX 10001
#define INF 9999999

vector<pair<int,pair<int, int>>> vec;

array<int, MAX> parent;

int V = 0, E = 0;

array<bool, MAX> bVisted = { false, };

//void dijkstra()
//{
//	priority_queue<pair<int, int>> pq;
//	pq.push( { vec[1].front().first, vec[1].front().second } );
//	iDistance[1] = 0;
//
//	while (!pq.empty())
//	{
//		int iCurNode = pq.top().first;
//		int iCurWeight = pq.top().second;
//		
//		pq.pop();
//
//		if(bVisted[iCurNode])
//			continue;
//
//		if(iDistance[iCurNode] < iCurWeight)
//			continue;
//
//
//		size_t vecSize = vec[iCurNode].size();
//		bVisted[iCurNode] = true;
//
//		for (size_t i = 0; i < vecSize; ++i)
//		{
//			int iNextNode = vec[iCurNode][i].first;
//			int iNextDistance = vec[iCurNode][i].second;
//
//			if (iNextDistance + iCurWeight < iDistance[iNextNode])
//			{
//				iDistance[iNextNode] = iNextDistance + iCurWeight;
//				pq.push({ iNextNode,iDistance[iNextNode] });
//			}
//		}
//	}
//
//	
//
//
//
//
//}
//
//
//
//int main()
//{
//	cin >> V >> E;
//
//	int iNum1,iNum2, iWeight = 0;
//	for (int i = 0; i < E; ++i)
//	{
//		cin >> iNum1 >> iNum2 >> iWeight;
//		vec[iNum1].push_back({ iNum2,iWeight });	
//	}
//
//	memset(&iDistance, INF, sizeof iDistance);
//	dijkstra();
//
//
//	cout << iDistance[V];
//
//
//}

int Find_Parent(int x)
{
	if (parent[x] == x)return x;
	return parent[x] = Find_Parent(parent[x]);
}

void Union(int x, int y)
{
	x = Find_Parent(x);
	y = Find_Parent(y);

	if (x != y)
		parent[y] = x;
}



bool SameParent(int x, int y)
{
	x = Find_Parent(x);
	y = Find_Parent(y);

	if (x == y)
		return true;

	return false;
}



void Solve()
{
	int Anwser = 0;

	for(int i=0; i<V; ++i )
	{
		parent[i] = i;
	}

	for (int i = 0; i < E; ++i)
	{
		if (SameParent(vec[i].second.first, vec[i].second.second) == false)
		{
			Union(vec[i].second.first, vec[i].second.second);
			Anwser = Anwser + vec[i].first;
		}
	}

	cout << Anwser;
}

int main()
{
	cin >> V >> E;

	int iNum1 = 0, iNum2 = 0, iWeight = 0;

	for (int i = 0; i < E; ++i)
	{
		cin >> iNum1 >> iNum2 >> iWeight;

		vec.push_back({ iWeight,{iNum1,iNum2} });
	}

	sort(vec.begin(), vec.end(), [&](auto Pair, auto Pair2)->bool
	{
		return Pair.first < Pair2.first;
	});

	Solve();
}