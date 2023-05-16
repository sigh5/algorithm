#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <set>

using namespace std;

#define MAX_N 15

array<int, MAX_N> Save_ChessQuene_Arr; // 1. Quene 들은 다른 행에 있어야한다.
									   // 2. Quene 들은 대각선이 걸리면안된다.	

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
		Save_ChessQuene_Arr[iQueenIndex] = i;		// 행의 데이터를 넣는다.
		bool bIsAttack = false;

		for (int j = 0; j < iQueenIndex; ++j)	 // 1. 앞에 있는 queue의 데이터를 기억하는 값들하고 비교 
		{										 // 2. 대각선 위치에 있는지 비교한다.  4x4 에서 대각선은 4차이가난다. 
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

int main()		// 퀸의 이동은 가로,세로, 대각선 에 다른 퀸이 있으면 안된다. 
{				
	cin >> N;

	dfs(0);

	cout << iAnswer;

}
