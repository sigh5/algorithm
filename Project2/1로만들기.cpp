#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <assert.h>
#include <math.h>
using namespace std;

const unsigned long long MaxNum = pow(10, 6);

vector<unsigned long long> vec;



int main()
{
	vec.resize(MaxNum, 0);

	unsigned long long N = 0;
	cin >> N;
	
	
	
	// 바텀업방식(반복문) 탑업(재귀함수)
	for (int i = 2; i <= N; ++i)
	{
		vec[i] = vec[i - 1] + 1;
		if ((i % 3) == 0) vec[i] = min(vec[i], vec[i / 3] + 1);
		if ((i % 2) == 0) vec[i] = min(vec[i], vec[i / 2] + 1);
	}

		
	cout << vec[N];

}