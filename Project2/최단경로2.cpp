#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <list>

using namespace std;

#define	INF 987654321
#define MAX 20010
int V, E, K;

vector<pair<int, int>>Vertex[MAX];
int Dist[MAX];

void Dijkstra()
{
	priority_queue<pair<int,int>> pq;
	pq.push({ 0,K });
	Dist[K] = 0;

	while (!pq.empty())
	{
		int current = pq.top().second;
		int CDistance= -pq.top().first;
		pq.pop();
		
		if (Dist[current] < CDistance)
			continue;

		for (int i = 0; i < Vertex[current].size(); ++i)
		{
			int Next = Vertex[current][i].first;
			int nDistance = Vertex[current][i].second;

			if (nDistance + CDistance < Dist[Next])
			{
				Dist[Next] = nDistance + CDistance;
				pq.push({ -Dist[Next],Next });
			}

				
		}
	}


	for (int i = 1; i <= V; ++i)
	{
		if (Dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", Dist[i]);
		
	}



}


void Dijkstra2()
{

}


int main()
{
	scanf("%d %d", &V, &E);
	scanf("%d", &K);

	int iStart = K;
	int u = 0, v = 0, w = 0;

	for (int i = 1; i <= V; ++i)
	{
		scanf("%d  %d  %d ", &u, &v, &w);
		Vertex[u].push_back({ v,w});
	}

	for (int i = 1; i <= V; ++i)
	{
		Dist[i] = INF;
	}

	Dijkstra();

}