#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int solution(std::vector<int> total_Amount,int n, int m)
{
	int answer = 0;

	int min = 1, max = 0, middle = 0;

	sort(total_Amount.begin(), total_Amount.end(),[](int a, int b)
	{
		return a > b;
	});

	max = total_Amount[0];


	while (min <= max)
	{
		middle = (min + max) / 2;
		int Sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (middle < total_Amount[i])
				Sum += middle;
			else
				Sum += total_Amount[i]; 
		}

		if (Sum > m) // 조건 성립 X 작은 middle 값을 찾으러간다.
		{
			max = middle - 1;
		}
		else  // 조건 성립 더 큰 값을 찾으러간다.
		{
			if (answer < middle)
				answer = middle;

			min = middle + 1;
		}


	}

	return answer;
}

int main()
{
	int n = 0;
	int m = 0;
	cin >> n;
	std::vector<int> total_Amount(n, 0);

	int number = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> total_Amount[i];
	}

	cin >> m;


	cout << solution(total_Amount, n,m);

	return 0;
}