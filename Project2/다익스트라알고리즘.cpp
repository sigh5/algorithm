#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <list>
using namespace std;

// �߰��� ��� �� ��ĵ 
// ���߿� ����� ���� �� ���� ��
// �̾���� ��� ����� �ٽ��� 0 -> 1 -> 2������ ���� ��� ���
// �θ��� �ڽ�Ʈ�� +  ���� �ڽ� �ڽ�Ʈ
// ���� �߰��� �Ͱ� ���� ����� ���� �߰��� �༮�� ������ ������ �����ߴ� �ڽ�Ʈ�� ����� 
// ���� �����Ѵ�. 

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent; // �������

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

	list<VertexCost>	discovered; // �߰߸��
	vector<int> best(6, INT32_MAX); // �� �������� ���ݱ��� �߰��� �ּҰŸ�
	vector<int> parnet(6, -1);

	discovered.push_back(VertexCost{ iStart,0 });
	best[iStart] = 0;
	parnet[iStart] = iStart;
	while (discovered.empty() == false)
	{
		// ���� ���� �ĺ��� ã�´�.
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

		// �湮 ? �� �F�� ��θ� �ڴʰ� ã�Ҵٸ� ��ŵ
		if (best[iStart] < cost)
			continue;

		// �湮 !
		for (int there = 0; there < 6; ++there)
		{
			// ������� �ʾ����� ��ŵ
			if (adjacent[iStart][there] == -1)
				continue;
			// �θ��� + �ڽ� ���
			int nextCost = best[iStart] + adjacent[iStart][there];
			// �� ���� ��θ� ���ſ� ã������ ��ŵ
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