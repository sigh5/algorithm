#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;



int main()
{
	int n = 0;
	cin >> n;
	vector<int> water(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> water[i];
	
	int answer0 = 0,answer1 = 0;
	
	sort(water.begin(), water.end());
	int imin = 0, imax = n - 1;

	int MinMin = 2000000000;
	while (imin < imax)
	{
		int Sum = water[imin] + water[imax];

		if (MinMin > abs(Sum))
		{
			answer0 = water[imin];
			answer1 = water[imax];
			MinMin = abs(Sum);

			if (Sum == 0)
				break;
		}

		if (Sum > 0)
		{
			imax -= 1;
		}
		else
			imin += 1;

	}

	cout << answer0 << " " << answer1 << endl;

}
