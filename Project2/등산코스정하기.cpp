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

    // 1) ���Ա� -> ����츮 -> ���Ա� ���� ���� ���� ���ڸ������� ������ ���� ����� 
    // 2) �ش� ����츮 ���ڰ� ���� �������� ã�´�.




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