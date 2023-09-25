#include <iostream>
#include <string>
#include <list>
#include <array>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
   
    int DivNum = s / n ;
    int RestNum = n - (s % n);

    if (n > s)
    {
        answer.push_back(-1);
        return answer;
    }


    for (int i = 0; i < RestNum; ++i)
    {
        answer.push_back(DivNum);
    }

    for (int i = RestNum; i < n; ++i)
    {
        answer.push_back(DivNum + 1);
    }

    return answer;
}

int main()
{

    solution(2, 9);

    return 0;
}