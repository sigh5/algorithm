#include <iostream>
#include <list>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end(), [](auto a, auto b)
        {
            return  a < b;
        });

    int iEndNum = routes[0][1];

    for (int i = 1; i < routes.size(); ++i)
    {
        if (routes[i][0] <= iEndNum || routes[i][1] <= iEndNum)
        {
            iEndNum = min(routes[i][1], iEndNum);
        }
        else
        {
            answer++;
            iEndNum = routes[i][1];
        }

    }





    return answer;
}


int main()
{
    vector<vector<int>> routes{ {-20,-15} ,{-14,-5},{-18,-13},{-5,-3} };

    solution(routes);

    return 0;
}