#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <list>
using namespace std;

// 발견한 놈들 쭉 스캔 
// 그중에 비용이 낮은 놈 먼저 들어감
// 이어가지고 비용 계산을 다시함 0 -> 1 -> 2번까지 가는 비용 계산
// 부모의 코스트와 +  현재 자식 코스트
// 먼저 발견한 것과 적은 비용을 통해 발견한 녀석이 있으면 기존의 예약했던 코스트를 지우고 
// 새로 갱신한다. 

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent; // 인접행렬

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));

	adjacent[0][1] = 15;
	adjacent[0][3] = 35;

	adjacent[1][0] = 15;
	adjacent[1][2] = 5;
	adjacent[1][3] = 10;

	adjacent[3][4] = 5;
	adjacent[5][4] = 5;

}

void Dijikstra(int iStart)
{
	struct VertexCost
	{
		int vertex;
		int cost;
	};

	list<VertexCost>	discovered; // 발견목록
	vector<int> best(6, INT32_MAX); // 각 정점별로 지금까지 발견한 최소거리
	vector<int> parnet(6, -1);

	discovered.push_back(VertexCost{ iStart,0 });
	best[iStart] = 0;
	parnet[iStart] = iStart;
	while (discovered.empty() == false)
	{
		// 제일 좋은 후보를 찾는다.
		list<VertexCost>::iterator bestIter;
		int bestCost = INT32_MAX;

		for (auto it = discovered.begin(); it != discovered.end(); ++it)
		{
			const int cost = it->cost;

			if (cost < bestCost )
			{
				bestCost = cost;
				bestIter = it;
			}
		}

		int cost = bestIter->cost;
		iStart = bestIter->vertex;
		discovered.erase(bestIter);

		// 방문 ? 더 짦은 경로를 뒤늦게 찾았다면 스킵
		if (best[iStart] < cost)
			continue;

		// 방문 !
		for (int there = 0; there < 6; ++there)
		{
			// 연결되지 않았으면 스킵
			if (adjacent[iStart][there] == -1)
				continue;
			// 부모비용 + 자식 비용
			int nextCost = best[iStart] + adjacent[iStart][there];
			// 더 좋은 경로를 과거에 찾았으면 스킵
			if (nextCost >= best[there])
				continue;

			discovered.push_back(VertexCost{ there,nextCost });
			best[there] = nextCost;
			parnet[there] = iStart;
		}

	}
	int a = 3;
}


int main()
{
	CreateGraph();
	Dijikstra(0);

}