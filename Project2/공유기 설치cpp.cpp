#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> vec, int n,int c)
{
	// n = vec.size();
	
	sort(vec.begin(), vec.end());
	
	long long min = 1;		 // 가장 최소의 거리
	long long max = (long long)vec[(n - 1)] ; // 가장 최대의 거리 0~ (long long)vec[(n - 1)]
	long long middle = 0;
	int answer = max;

	while (min <= max)
	{
		middle = (min + max) / 2;

		int cnt = 1;
		int prevNum = 0;
		for (int i = 1; i < n; ++i)
		{
			if (vec[i] - vec[prevNum] >= middle) // 이전 공유기와 현재 공유기의 위치를 찾는다.
			{
				prevNum = i;
				++cnt;
			}
		}

		if (cnt < c)  // 원하는 공유기 숫자가 적다. 거리를 줄여야한다.
		{
			max = middle - 1;
		}
		else // cnt >=c 원하는 공유기 숫자보다 많거나 같다.
		{
			answer = middle;

			min = middle + 1; // 거리를 늘려 공유기 숫자를 줄인다.
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