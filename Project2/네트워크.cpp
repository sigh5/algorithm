#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <queue>
using namespace std;


bool dfs(vector<vector<int>>& computers, int iStartNode)
{
    if (computers[iStartNode][iStartNode] == 0)
        return false;

    computers[iStartNode][iStartNode] = 0;

    for (int i = 0; i < computers.size(); ++i)
    {
        if (i != iStartNode && computers[iStartNode][i] == 1)
            dfs(computers, i);
    }

    return true;
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; ++i)
    {
        if (computers[i][i] == 1 && dfs(computers, i))
            answer++;
    }

    return answer;
}

int main()
{
    vector<vector<int>> computers{ {1, 1, 0} , {1, 1, 0} ,{0, 0, 1} };

    solution(3, computers);

    return 0;
}