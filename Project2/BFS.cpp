#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> discovered;

void CreateGraph()
{
	vertices.resize(6);

	adjacent = vector<vector<int>>(6);

	// ��������Ʈ
	/*adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);*/

	// �������
	adjacent = vector<vector<int>>
	{
		{ 0,1,0,1,0,0 },
		{ 1,0,1,1,0,0 },
		{ 0,0,0,0,0,0 },
		{ 0,0,0,0,1,0 },
		{ 0,0,0,0,0,0 },
		{ 0,0,0,0,1,0 }
	};

}

void Bfs(int iStart)
{
	// ������ ���� �߰� �Ǿ�����?
	vector<int> parent(6, -1);
	// ���������� ��ŭ ������ �ִ���?
	vector<int> distance(6, -1);


	queue<int> q;
	q.push(iStart);
	discovered[iStart] = true;

	parent[iStart] = iStart;
	distance[iStart] = 0;


	while (!q.empty())
	{
		iStart = q.front();
		q.pop();

		cout << "Visted : " << iStart << endl;

		//for (int there : adjacent[iStart]) // ���� ����Ʈ
		for(int there =0; there <6;  ++there) // �������
		{
			if (adjacent[iStart][there]==0)
				continue;

			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;

			parent[there] = iStart;
			distance[there] = distance[iStart] + 1;
		}

	}

	int a = 3;
}


int main()
{
	CreateGraph();

	discovered = vector<bool>(6, false);

	Bfs(0);
}