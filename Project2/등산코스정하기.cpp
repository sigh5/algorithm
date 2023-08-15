#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    vector<int> answer;

  
    vector<vector<int>> Temp( n+1, vector <int>(n+1) );

    for (int i = 0; i < paths.size(); ++i)
    {
        Temp[paths[i][0]][paths[i][1]] = paths[i][2];
        Temp[paths[i][1]][paths[i][0]] = paths[i][2];
    }

    // 1) 출입구 -> 산봉우리 -> 출입구 에서 가장 작은 인텔리젼스를 가지는 것을 만들고 
    // 2) 해당 산봉우리 숫자가 제일 작은것을 찾는다.




    return answer;
}

int main()
{

    vector<vector<int>> paths{ {1, 2, 3} ,{2, 3, 5},{2, 4, 2},{2, 5, 4},{3, 4, 4},{4, 5, 3},{4, 6, 1},{5, 6, 1} };
    vector<int> gates{ 1, 3 };
    vector<int> summits{5};

    solution(6 , paths, gates, summits);
    return 0;
}