#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main()
{
    vector<int> nums = {3,3,1,2};

    int OriginNumsSize = nums.size();
    int answer = OriginNumsSize / 2;

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int eraseUniqueVec_Num = nums.size();

    if (answer >= eraseUniqueVec_Num)
        answer = eraseUniqueVec_Num;
    
	return 0;
}