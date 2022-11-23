#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <memory.h>
#include <array>

using namespace std;

#define MAX 101

int iCompareNode1=0, iCompareNode2 = 0;

int N = 0, M = 0;

vector<int> vec[MAX];
array<bool, MAX> bVisted = { false, };

int iCount = 0;
bool bControl = false;
void dfs(int iNode1, int iNode2, int iCnt)
{
	if (bVisted[iNode1])
		return;

	bVisted[iNode1] = true;

	if (iNode1 == iNode2)
	{
		iCount = iCnt;
		bControl = true;
		return;
	}

	for (int i = 0; i < vec[iNode1].size(); ++i)
	{
		if (!bVisted[vec[iNode1][i]])
		{
			dfs(vec[iNode1][i], iNode2, iCnt + 1);
			if (bControl)
				break;
		}
	}


}



int main()
{
	cin >> N;
	cin >> iCompareNode1 >> iCompareNode2;
	cin >> M;

	int iParent = 0, iChild = 0;

	for (int i = 0; i < M; ++i)
	{
		cin >> iParent >> iChild;
		vec[iParent].push_back(iChild);
		vec[iChild].push_back(iParent);
	}




	dfs(iCompareNode1, iCompareNode2,0);


	if (iCount == 0)
		cout << -1;
	else
		cout << iCount;
	
}
