#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool Check(map<string, int> wantMap, map<string, int> ResultMap)
{
    bool bResult = true;

    for (auto temp : wantMap)
    {
        if (ResultMap.find(temp.first) == ResultMap.end())
        {
            return false;
        }
        else if (ResultMap[temp.first] != temp.second)
            return false;

    }


    return bResult;

}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int disCountSize = discount.size();
    int wantSize = want.size();

    map<string, int> Wantmap;
    for (int i = 0; i < wantSize; ++i)
    {
        Wantmap[want[i]] = number[i];
    }


    for (int i = 0; i <= disCountSize - 10; ++i)
    {
        map<string, int> ResultMap;

        for (int j = i; j < i + 10; ++j)
        {
            ResultMap[discount[j]] ++;
        }

        if (Check(Wantmap, ResultMap))
            answer++;

        ResultMap.clear();
    }

    return answer;
}

int main()
{
    vector<string> want{ "banana", "apple", "rice", "pork", "pot" };
    vector<int> number{ 3, 2, 2, 2, 1 };
    vector<string> discount{"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"};
    solution( want,  number, discount);



    return 0;
}