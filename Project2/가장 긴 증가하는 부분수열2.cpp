#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;


int binary_search(vector<int>& arr, int key)
{
	int lo = 0, hi = arr.size() - 1, mid;

	while (lo < hi) {
		mid = lo + (hi - lo) / 2;

		if (arr[mid] >= key)
			hi = mid;
		else lo = mid + 1;
	}

	return hi;
}


int solution(vector<int> vec,int n)
{
	vector<int> result;
	result.reserve(n);
	result.push_back(vec[0]);

	for (int i = 1; i < n ; ++i)
	{
		if (result.back() < vec[i])
		{
			result.push_back(vec[i]);
		}
		else
		{
			int idx = binary_search(result, vec[i]);
			result[idx] = vec[i];
		}
			
	}
	
	return result.size();
}



int main()
{

	int n = 0;

	cin >> n;
	vector<int > vec(n, 0);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}


	cout << solution(vec, n);


}