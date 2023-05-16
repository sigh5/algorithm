#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <set>

using namespace std;

#define MAX_N 15

array<int, MAX_N> Save_ChessQuene_Arr; // 1. Quene ���� �ٸ� �࿡ �־���Ѵ�.
									   // 2. Quene ���� �밢���� �ɸ���ȵȴ�.	

int N = 0;
int iAnswer = 0;

void dfs(int iQueenIndex)
{
	if (iQueenIndex == N)
	{
		++iAnswer;
		return;
	}


	for (int i = 0; i < N; ++i)
	{
		Save_ChessQuene_Arr[iQueenIndex] = i;		// ���� �����͸� �ִ´�.
		bool bIsAttack = false;

		for (int j = 0; j < iQueenIndex; ++j)	 // 1. �տ� �ִ� queue�� �����͸� ����ϴ� �����ϰ� �� 
		{										 // 2. �밢�� ��ġ�� �ִ��� ���Ѵ�.  4x4 ���� �밢���� 4���̰�����. 
			if (Save_ChessQuene_Arr[iQueenIndex] == Save_ChessQuene_Arr[j]
				|| (abs(Save_ChessQuene_Arr[iQueenIndex] - Save_ChessQuene_Arr[j]) == abs(iQueenIndex - j)))
			{
				bIsAttack = true;
				break;
			}
		}

		if(bIsAttack == false)
			dfs(iQueenIndex + 1);
	}
	
	
}

int main()		// ���� �̵��� ����,����, �밢�� �� �ٸ� ���� ������ �ȵȴ�. 
{				
	cin >> N;

	dfs(0);

	cout << iAnswer;

}
