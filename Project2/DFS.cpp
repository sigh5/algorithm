#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;


struct Vertex
{

};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool>	visited;
void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6);

	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);
}



// DFS
void Dfs(int iStart)
{
	if (visited[iStart])
		return;

	visited[iStart] = true;

	// 인접 리스트 version
	// 모든 인접 정점을 순회한다.


	for (size_t i=0; i < adjacent[iStart].size(); ++i)
	{
		int iCur = adjacent[iStart][i];
		if (visited[iCur] == false)
			Dfs(iCur);
	}



}


int main()
{
	CreateGraph();

	visited = vector<bool>(6, false);

	Dfs(0);
}