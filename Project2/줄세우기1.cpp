#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <memory.h>
#include <array>

using namespace std;

#define MAX 32001

int N = 0, M = 0;


vector<int> vec[MAX];
array<int,MAX> inDegree;


void topologySort()
{
	queue<int> q;

	for (int i = 1; i <= N; ++i)
	{
		if(inDegree[i] ==0)
			q.push(i);
	}

	while(!q.empty())
	{	
		int CurrentNode = q.front();
		q.pop();
		
		cout << CurrentNode<< " " ;

		for (int i = 0; i < vec[CurrentNode].size(); ++i)
		{
			int NewNode = vec[CurrentNode][i];

			if (--inDegree[NewNode] == 0)
			{
				q.push(NewNode);
			}
		}

	}




}


int main()
{
	cin >> N >> M;

	int iTall = 0, iSmall = 0;

	for (int i = 0; i < M; ++i)
	{
		cin >> iTall >> iSmall;
		vec[iTall].push_back(iSmall);
		++inDegree[iSmall];
	}



	topologySort();


}