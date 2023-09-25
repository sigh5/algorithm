#include <iostream>
#include <list>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;


int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int Size = stations.size();
    
    int Range = w * 2 + 1;
    
    int cnt = 0;
    // 가장 왼쪽
    cnt = stations[0] - w - 1 > 0 ? stations[0] - w - 1 : 0;
    answer += (cnt / Range);
    answer += (cnt % Range) != 0 ? 1 : 0;

    // 중앙
    for (int i = 1; i < Size; ++i)
    {
        cnt = stations[i] - stations[i - 1] -Range > 0 ? stations[i] - stations[i - 1] - Range : 0;
        answer += (cnt / Range);
        answer += (cnt % Range) != 0 ? 1 : 0;
    }

    // 가장 오른쪽 전파를 못받는 곳
    cnt = stations[Size -1 ] - w - 1 < n ? stations[Size - 1] - w - 1 : 0;
    answer += (cnt / Range);
    answer += (cnt % Range) != 0 ? 1 : 0;


    return answer;
}

int main()
{
    vector<int> stations{4,11};

    solution(11, stations, 1);
    return 0;
}