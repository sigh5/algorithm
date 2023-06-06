#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

int iTargetEqual = 0;

void dfs(vector<int> numbers, int target, int iDepth, int iResult)
{
    if (iDepth >= numbers.size())
    {
        if (target == iResult)
            ++iTargetEqual;

        return;
    }

   

    for (int i = 0; i < 2; ++i)
    {
        if (i == 0)
        {
            dfs(numbers, target, iDepth+1, iResult + numbers[iDepth]);
        }
        else
        {
            dfs(numbers, target, iDepth+1, iResult - numbers[iDepth]);
        }
    }
}


int solution(vector<int> numbers, int target) {
    int answer = 0;

    for (int i = 0; i < 2; ++i)
    {
        if (i == 0)
        {
            dfs(numbers, target, 1, +numbers[0]);
        }
        else
        {
            dfs(numbers, target, 1, -numbers[0]);
        }
    }
    answer = iTargetEqual;
    return answer;
}

int main()
{
    vector<int> Numbers{ 4,1,2,1, };

    cout << solution(Numbers, 4);

    bool b = false;

	return 0;
}
