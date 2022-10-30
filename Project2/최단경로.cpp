#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <list>
using namespace std;

#define		MAX			20001
#define		MAX_EDGE	300000

int V, E;
int iStart = 0;

struct Vertex
{

};

vector<Vertex> vertices;
vector<vector<int>> adjacent;



void CreateGraph()
{
	iStart = 0;
	cin >> V >> E;

	cin >> iStart;

	vertices.resize(V+1);
	adjacent = vector<vector<int>>(V+1, vector<int>(V+1, -1));

	int u = 0, v = 0, w = 0;

	for (int i = 1; i <= E; ++i)
	{
		cin >> u >> v >> w;
		adjacent[u][v] = w;
	}

	


	
}


void Dijkstra(int iStart)
{
	struct VertexCost
	{
		int vertex;
		int cost;
	};

	list<VertexCost> discorverd;
	vector<int> best(V + 1, INT32_MAX);
	vector<int> parent(V + 1, -1);

	discorverd.push_back(VertexCost{iStart,0});
	best[iStart] = 0;
	parent[iStart] = iStart;

	while (!discorverd.empty())
	{
		// 제일 좋은 후보를 찾는다.
		list<VertexCost>::iterator bestIter;
		int bestCost = INT32_MAX;

		for (auto iter = discorverd.begin(); iter != discorverd.end(); ++iter)
		{
			if (iter->cost < bestCost)
			{
				bestCost = iter->cost;
				bestIter = iter;
			}
		}

		int cost = bestIter->cost;
		iStart = bestIter->vertex;
		discorverd.erase(bestIter);

		// 방문 ? 더 짦은 경로를 뒤늦게 찾았다면 스킵
		if (best[iStart] < cost)
		{
			continue;
		}

		// 방문! 

		for (int there = 1; there <= V; ++there)
		{
			// 연결되지 않았으면 스킵
			if (adjacent[iStart][there] == -1)
				continue;
			// 부모비용 + 자식비용
			int nextCost = best[iStart] + adjacent[iStart][there];

			// 더 좋은 경로를 과거에 찾았으면 스킵
			if (nextCost >= best[there])
				continue;

			discorverd.push_back(VertexCost{ there,nextCost });
			best[there] = nextCost;
			parent[there] = iStart;

		}

	}

	//int i = best.size();
	for (int i = 1; i <= V; ++i)
	{
		if (best[i] == INT32_MAX)
		{
			cout << "INF" << endl;
			continue;
		}
		cout << best[i] << endl;
	}

}



int main()
{
	CreateGraph();

	Dijkstra(iStart);


	


}