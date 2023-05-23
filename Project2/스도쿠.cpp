#include <iostream>
#include <string>
#include<vector>
#include <array>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

array<int,81> Sdoku;
// 1. �� �࿡ 1~9 ������ ���� �־���Ѵ�. Row �� ���� ��� �����  // 9��
// 2. �� ���� 1~9 ������ ���� �־���Ѵ�. Column�� ���� ��ĸ���� // 9��
// 3. 3x3 ���簢���� 1~9������ ���� �־���Ѵ�, // 9��
 
//3x3�� ���� ��� �����

vector <int> ZeroSdoku;  // (Row,Col,Rentangle ����) , �ε���
array<int, 9> SortNum{ 1,2,3,4,5,6,7,8,9 };

void RowCheck()
{
	vector< int> ZeroData[9]; // Row, Col

	for (int i = 0; i < ZeroSdoku.size(); ++i)
	{
		int Row = ZeroSdoku[i] % 9;
		
		ZeroData[Row].push_back({ ZeroSdoku[i] });
		
	}

	array<int, 9>CurRowData{ 0 };

	for (int i = 0; i < 9; ++i)
	{
		if (ZeroData[i].size() > 2)
			continue;

		for (int j = 0; j < 9; ++j)
		{
			CurRowData[j] = Sdoku[(i * 9) + j];
		}

		sort(CurRowData.begin(), CurRowData.end());

		for (int q = 0; q < 9; ++q)
		{
			if (CurRowData[q] != SortNum[q])
			{

				break;
			}
		}
	}



	// Vector �ٽ� ����

}

void ColumnCheck()
{

}

void RentangleCheck()
{

}

int main()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> Sdoku[(i*9) + j];

			if (Sdoku[(i * 9) + j] == 0)
				ZeroSdoku.push_back({ (i * 9) + j });
		}
	}

	RowCheck();
	ColumnCheck();
	RentangleCheck();

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << Sdoku[(i * 9) + j] << " ";
		}
		puts("");
	}


	return 0;
}