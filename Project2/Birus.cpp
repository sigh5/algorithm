#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define		MAX 101

int N, M;

bool visited[MAX];
vector<int> vertices[MAX];

int iCount = 0;

void Dfs(int iStart)
{
	if (visited[iStart])
		return;

	visited[iStart] = true;

	size_t size = vertices[iStart].size();

	for (size_t i = 0; i < size; ++i)
	{
		int iHere = vertices[iStart][i];
		if (!visited[iHere])
		{
			++iCount;
			Dfs(iHere);
		}
	}


}


int main()
{
	cin >> N;
	cin >> M;

	int a = 0 , b = 0;

	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;

		vertices[a].push_back(b);
		vertices[b].push_back(a);
	}

	Dfs(1);

	cout << iCount;

}