#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;

    vector<long long> cnt(1001, 0);

    int WeigtsSize = weights.size();

    for (int i = 0; i < WeigtsSize; ++i)
    {
        cnt[weights[i]]++;
    }

    long long CntIdx = 0;

    for (int i = 0; i < WeigtsSize; ++i)
    {
        if (weights[i] % 2 == 0)  // 2:3, 3:4
        {
            CntIdx = (weights[i] / 2) * 3;
            if (CntIdx <= 1000)
                answer += cnt[CntIdx];
        }

        if (weights[i] % 3 == 0) // 3:4
        {
            CntIdx = (weights[i] / 3) * 4;
            if (CntIdx <= 1000)
                answer += cnt[CntIdx];
        }


        CntIdx = weights[i] * 2;  //2 :4
        if (CntIdx <= 1000)
            answer += cnt[CntIdx];





    }
    for (int i = 100; i <= 1000; ++i)
    {
        if (cnt[i] >= 2)
        {
            answer += (long long)(cnt[i] * (cnt[i] - 1)) / 2;
        }
    }


    return answer;
}

int main()
{
    vector<int> weights{ 100,180,360,100,270 };

    solution(weights);

    return 0;
}