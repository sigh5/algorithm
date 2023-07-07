#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), [](auto& a, auto& b) {
        return a < b;
        });

    return answer;
}

int main()
{
	vector<vector<int>> targets{ {4,5} ,{4,8},{10,14},
		{11,13},{5,12},{3,7},{1,4} };

	solution(targets);

	return 0;
}