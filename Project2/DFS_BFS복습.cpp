#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int N = 0, M = 0;
vector<int> vecNode[1001];
bool bVisted[1001];

void dfs(int iStart)
{
	if (bVisted[iStart])
		return;

	bVisted[iStart] = true;
	cout << iStart << " ";


	sort(vecNode[iStart].begin(), vecNode[iStart].end(), [&](int a, int b)->bool
	{
		return a < b;
	});


	size_t vecSize = vecNode[iStart].size();

	for (size_t i = 0; i <vecSize; ++i)
	{
		dfs(vecNode[iStart][i]);
	}
}

void bfs(int iStart)
{
	queue<int> q;
	bVisted[iStart] = true;
	q.push(iStart);


	


	while (!q.empty())
	{
		int iFront = q.front();
		q.pop();
		cout << iFront<<" ";
		size_t vecSize = vecNode[iFront].size();

		for (size_t i = 0; i < vecSize; ++i)
		{
			if (!bVisted[vecNode[iFront][i]])
			{
				q.push(vecNode[iFront][i]);
				bVisted[vecNode[iFront][i]] = true;
			}
		}
	}

}




int main()
{
	int iStartNode = 0;

	cin >> N >> M >> iStartNode;

	int iStart = 0, iEnd = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> iStart >> iEnd;
		vecNode[iStart].push_back(iEnd);
		vecNode[iEnd].push_back(iStart);
	}

	dfs(iStartNode);
	puts("");
	memset(bVisted, false, sizeof(bVisted));

	bfs(iStartNode);



}


// dfs ����
// ������ �̿��Ͽ� Ǫ�� ��
// 1. ������ �ֻ�� ��带 Ȯ���մϴ�.
// 2. �ֻ�� ��忡�� �湮���� ���� ������尡 �ִٸ� �湮�Ѵ�.


