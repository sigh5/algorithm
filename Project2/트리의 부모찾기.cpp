#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <array>
#include <memory.h>

using namespace std;

#define MAX 100001

int N = 0;

vector<long long> vec[MAX];
array<long long, MAX>   iParent;
array<bool, MAX> bVisted = { false, };

void dfs(int iStart)
{
	if (bVisted[iStart])
		return;

	bVisted[iStart] = true;

	size_t size = vec[iStart].size();

	for (size_t i = 0; i < size; ++i)
	{
		if (!bVisted[vec[iStart][i]])
		{
			dfs(vec[iStart][i]);
			iParent[vec[iStart][i]] = iStart;
		}
	}

}




int main()
{
	cin >> N;

	long long iNum1 = 0, iNum2=0;

	for (int i = 1; i < N; ++i)
	{
		cin >> iNum1;
		cin >> iNum2;

		vec[iNum1].push_back(iNum2);
		vec[iNum2].push_back(iNum1);
	}

	dfs(1);

	for (int i = 2; i <= N; ++i)
	{
		cout << iParent[i] << "\n";
	}
}


