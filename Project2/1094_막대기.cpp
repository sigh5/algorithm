#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int X)
{
	int answer = 1;

	int originX = 64,Sum=64;

	while (Sum >X)
	{
		originX >>= 1;

		if (Sum - originX >= X)
		{
			Sum -= originX;
		}
		else
		{
			answer++;
		}

	}


	return answer;
}


int main()
{
	int x = 0;
	cin >> x;

	cout << solution(x);

	return 0;
}