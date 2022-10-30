#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool bVisited[9];
vector<int> Node;

int n=0, m=0;


void dfs(int start,int cnt)
{
	
	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << Node[i] << " ";
		}
		puts("");
		return;
	}

	for (int i = start; i <=n; ++i)
	{
		if (!bVisited[i])
		{
			bVisited[i] = true;
			Node[cnt] = i;
			dfs(i+1,cnt+1);
			bVisited[i] = false;
		}
	}




}


int main()
{
	cin >> n >> m;

	for (int i = 1; i<= n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			Node.push_back(j);
		}
	}

	dfs(1,0);
}