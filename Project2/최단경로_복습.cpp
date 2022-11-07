#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <array>


#pragma warning(disable : 4996)

using namespace std;

#define MAX 20001
#define INF 9999999 

int iVertex, iEdge = 0;
vector<pair<int, int>> vec[MAX]; // index = startVertex , first = End , Second = Weight
array<int, MAX> iDistance;


bool bVisited[MAX] = { false, };

void Dijstra(int _iStartVertex)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ _iStartVertex,0 });
	iDistance[_iStartVertex] = 0;

	while (!pq.empty())
	{
		auto current = pq.top();
		pq.pop();

		int iCurrentNode = current.first;
		int iCurrentWeight = -current.second;

		if(bVisited[iCurrentNode])
			continue;

		if(iDistance[iCurrentNode] < iCurrentWeight)
			continue;

		size_t vecSize = vec[iCurrentNode].size();
		bVisited[iCurrentNode] = true;

		for (int i = 0; i < vecSize; ++i)
		{
			int iNextNode = vec[iCurrentNode][i].first;
			int iNextDistance = vec[iCurrentNode][i].second;

			if (iNextDistance + iCurrentWeight < iDistance[iNextNode])
			{
				iDistance[iNextNode] = iNextDistance + iCurrentWeight;
				pq.push({ iNextNode,-iDistance[iNextNode] });
			}
		}

	}

	for (int i = 1; i <= iVertex; ++i)
	{
		if (iDistance[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", iDistance[i]);

	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> iVertex >> iEdge;
	int iStartNode;
	cin >> iStartNode;

	for (int i = 1; i <= iVertex; ++i)
	{
		iDistance[i] = INF;
	}

	int iStartVertex = 0, iEndVertex = 0, iWeight = 0;

	for (int i = 1; i <= iEdge; ++i)
	{
		cin >> iStartVertex >> iEndVertex >> iWeight;
		vec[iStartVertex].push_back({ iEndVertex,iWeight });
	}

	Dijstra(iStartNode);


}