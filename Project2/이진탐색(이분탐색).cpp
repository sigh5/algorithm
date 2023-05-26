#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <unor>
using namespace std;

const int Number = 12;

array<int, Number> arr{ 1,3,5,7,9,11,14,15,18,19,25,28 };
int Data = 7;

int Binary_Search(int start, int end, int target)
{
	if (start > end)
		return -1;

	int middle = (start + end) / 2;
	if (arr[middle] == target)
		return middle;
	else if (arr[middle] > target)
		Binary_Search(start, middle - 1, target);
	else
		Binary_Search(middle +1, end, target);

}

int main()
{
	int result = Binary_Search(0, Number - 1, Data);
	if (result != -1)
		cout << result+1 << " "<< endl;

		return 0;
}
