#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	int T = 0;
	int a = 0, b = 0;
	
	cin >> T;



	for (int i = 0; i < T; ++i)
	{
		long long iCount = 0;
		cin >> a >> b;

		if (b % 4 == 0)
		{
			b = 4;
		}
		else
		{
			b = b % 4;
		}

		iCount = pow(a, b);

		if (iCount % 10 == 0)
			iCount = 10;
		else
		{
			iCount %= 10;
		}

		cout << iCount << endl;

	}



}