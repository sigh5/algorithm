#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>

#define MAX_NODE 1001
#define MAX_EDGE 10001

using namespace std;


vector<int> vec[MAX_NODE];
bool visited[MAX_NODE] = { false, };

int N, M, V;


void dfs(int iStartNode)
{
	if (visited[iStartNode])
		return;

	visited[iStartNode] = true;

	cout << iStartNode << " ";

	size_t vecSize = vec[iStartNode].size();

	sort(vec[iStartNode].begin(), vec[iStartNode].end(), [](int a, int b)->bool
	{
		return a < b;
	});

	for (size_t i = 0; i < vecSize; ++i)
	{
		dfs(vec[iStartNode][i]);	
	}
}

void bfs(int iStartNode)
{
	queue<int> q;
	q.push(iStartNode);
	visited[iStartNode] = true;


	while (!q.empty())
	{
		int ifront = q.front();
		q.pop();

		cout << ifront << " ";

		size_t vecSize = vec[ifront].size();

		for (size_t i = 0; i < vecSize; ++i)
		{
			if (!visited[vec[ifront][i]])
			{
				q.push(vec[ifront][i]);
				visited[vec[ifront][i]] = true;
			}
			
		}




	}




}



int main()
{
	cin >> N >> M >> V;
	
	int iStartNode = 0, iEndNode = 0;

	for (int i = 0; i < M; ++i)
	{
		cin >> iStartNode >> iEndNode;

		vec[iStartNode].push_back(iEndNode);
		vec[iEndNode].push_back(iStartNode);
	}
	

	dfs(V);
	memset(visited, 0,sizeof(visited));

	cout << "\n";
	bfs(V);




}