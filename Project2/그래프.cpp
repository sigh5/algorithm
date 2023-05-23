#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int iMAX_Num = 1001;

vector<int> NodeVec[iMAX_Num];

array<int, iMAX_Num> bVisted{ false };

int N = 0, M = 0, V = 0;

void dfs(int iStart)
{
	if (bVisted[iStart])
		return;

	bVisted[iStart] = true;
	cout << iStart << " ";
	int vecsize = static_cast<int>(NodeVec[iStart].size());
	
	sort(NodeVec[iStart].begin(), NodeVec[iStart].end());

	for (int i = 0; i < vecsize; ++i)
	{
		if (false == bVisted[NodeVec[iStart][i]])
		{
			dfs(NodeVec[iStart][i]);
		}
	}

}

void bfs(int iStart)
{
	queue<int> q;
	q.push(iStart);
	bVisted[iStart] = true;

	while (!q.empty())
	{
		int CurIndex = q.front();
		cout << CurIndex << " ";
		q.pop();

		int vecsize = static_cast<int>(NodeVec[CurIndex].size());

		for (int i = 0; i < vecsize; ++i)
		{
			if (bVisted[NodeVec[CurIndex][i]] == false)
			{
				q.push(NodeVec[CurIndex][i]);
				bVisted[NodeVec[CurIndex][i]] = true;
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
		NodeVec[iStartNode].push_back(iEndNode);
		NodeVec[iEndNode].push_back(iStartNode);
	}

	dfs(V);
	bVisted.fill(false);
	puts("");
	bfs(V);

	return 0;
}