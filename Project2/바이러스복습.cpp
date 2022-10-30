#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define MAX 101

vector<int> vec[MAX];
bool bVistied[MAX];

int N = 0, M = 0;
int iCount = 0;


void Dfs(int iStart)
{
	if (bVistied[iStart])
		return;

	bVistied[iStart] = true;

	size_t size = vec[iStart].size();

	for (size_t i = 0; i < size; ++i)
	{
		int iHear = vec[iStart][i];

		if (!bVistied[iHear])
		{
			iCount++;
			Dfs(iHear);
		}
	}



}




int main()
{
	
	cin >> N >> M;

	int iNum1 = 0, iNum2 = 0;

	for (int i = 0; i < M; ++i)
	{
		cin >> iNum1 >> iNum2;

		vec[iNum1].push_back(iNum2);
		vec[iNum2].push_back(iNum1);
	}

	for (int i = 0; i < N; ++i)
	{
		sort(vec[i].begin(), vec[i].end(), [&](int a, int b)->bool
		{
			return a < b;
		});
	}


	Dfs(1);

	cout << iCount <<endl;
}


