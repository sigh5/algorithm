#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> vec, int n,int c)
{
	// n = vec.size();
	
	sort(vec.begin(), vec.end());
	
	long long min = 1;		 // ���� �ּ��� �Ÿ�
	long long max = (long long)vec[(n - 1)] ; // ���� �ִ��� �Ÿ� 0~ (long long)vec[(n - 1)]
	long long middle = 0;
	int answer = max;

	while (min <= max)
	{
		middle = (min + max) / 2;

		int cnt = 1;
		int prevNum = 0;
		for (int i = 1; i < n; ++i)
		{
			if (vec[i] - vec[prevNum] >= middle) // ���� ������� ���� �������� ��ġ�� ã�´�.
			{
				prevNum = i;
				++cnt;
			}
		}

		if (cnt < c)  // ���ϴ� ������ ���ڰ� ����. �Ÿ��� �ٿ����Ѵ�.
		{
			max = middle - 1;
		}
		else // cnt >=c ���ϴ� ������ ���ں��� ���ų� ����.
		{
			answer = middle;

			min = middle + 1; // �Ÿ��� �÷� ������ ���ڸ� ���δ�.
		}
	}


	return answer;
}


int main()
{
	int N = 0 ,C=0;
	cin >> N >> C;
	vector<int> vec;

	int Num = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> Num;
		vec.push_back(Num);
	}

	cout << solution(vec, N,C);

}