#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <unordered_set>

using namespace std;

int N = 0, K = 0;

bool cmp(int a, int b)
{
	return a > b;
}

int Solution(vector<long long> Lan, int NeedLan)
{
	int answer = 0;
	long long max=0, min=1, middle = 0;
	int LanSize = Lan.size();

	sort(Lan.begin(), Lan.end(),cmp);
	max = Lan[0];


	while (max >= min)
	{
		middle = (max + min) / 2;

		int Count = 0;

		for (int i = 0; i < LanSize; ++i)
		{
			if (Lan[i] >=1 && int(Lan[i] / middle) > 0)
			{
				Count += int(Lan[i] / middle);
			}
		}

		if (Count >= NeedLan) //     �ʿ䰳������ ���ų� ����  , middle ���� ���� �� ��� ¥����.
		{
			if(answer < middle)
				answer = middle;

			min = middle + 1;
		}
		else  // Count < NeedLan	// �ʿ䰳������ ���ڸ��� Middle ���� ���� �ڸ���.
		{
			max =  middle - 1  ;
		}


	}



	return answer;
}

int main()
{
	cin >> N >> K;

	vector<long long> Lan;

	long long iNum = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> iNum;
		Lan.push_back(iNum);
	}
	cout << Solution(Lan, K);

	return 0;
}