#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

#define MAX 50

array<int, MAX> AllArr{ 0 };	// ��� ������ ����
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

		// ��� 6�ڸ� ���� �̾� ���������� �ߺ��� �����ұ�?
		// �ð������� �ɸ���.
		// 6�ڸ��� �ִ�. 

		

		// 

		AllArr.fill(0); // ������ ���� ������ 0���� �ʱ�ȭ
		LottoArr.fill(0);
		puts("");
	}

	return 0;
}

