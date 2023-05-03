#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

#define MAX 50

array<int, MAX> AllArr{ 0 };	// 모든 원소의 집합
array<int, 6> LottoArr{ 0 };
int k = 0;

void dfs(int iStart,int iDepth)
{
	if (iDepth >= 6)
	{
		for (int i = 0; i < iDepth; ++i)
			cout << LottoArr[i] << " ";

		puts("");
		return;
	}

	for (int i = iStart; i < k; ++i)
	{
		LottoArr[iDepth++] = AllArr[i];
		dfs(i+1, iDepth+1);
		
	}
}

int main()
{
	

	while(cin >> k && k!=0)
	{ 
		for (int i = 0; i < k; ++i)
		{
			cin >> AllArr[i];
		}

		// To.Do 

		dfs(0, 0);

		// 모든 6자리 수를 뽑아 버린다음에 중복을 제거할까?
		// 시간제한이 걸린다.
		// 6자리가 있다. 

		

		// 

		AllArr.fill(0); // 로직이 끝난 집합은 0으로 초기화
		LottoArr.fill(0);
		puts("");
	}

	return 0;
}

