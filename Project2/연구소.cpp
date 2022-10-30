#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <memory>

using namespace std;

#define MAX 8

int xDir[4] = { 0,0,-1,1 };
int yDir[4] = { -1,1,0,0 };

int iGraph[MAX][MAX];

int N, M;


int main()
{
	string str;
	cin >> N >> M;

	
	for (int i = 0; i < N; ++i)
	{
		int a = 0;
		for (int j = 0; j < M; ++j)
		{
			cin >> a;
			iGraph[i][j] =a;
		}
	}

	bool b = false;


}
