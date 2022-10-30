#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int N = 0;

	cin >> N;

	int Number = 0;

	while (N >= 0)
	{
		if (N % 5==0)
		{
			Number += (N / 5);
			cout << Number << endl;
			break;
		}

		N -= 3;
		Number++;
		
		if (N < 0)
		{
			cout << -1;
			break;
		}

	}

	
	return 0;

}