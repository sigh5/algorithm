#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {


    sort(times.begin(), times.end());

    long long min = 1;  // 걸리는 시간 1초 모든 사람들이 최소로 끝나는 시간
    long long max = (long long)times[times.size() - 1] * n; // 모든 사람들이 최대로 끝나는 시간

    long long answer = max;


    while (min <= max)
    {
        long long middle = (min + max) / 2; // 중간값

        long long Cnt = 0; // 입국허가 받은 사람들의 수

        for (int i = 0; i < times.size(); ++i)
        {
            // 각 시간별로 처리할 수 있는 사람 수
            Cnt += middle / times[i];
        }

        if (Cnt < n) // 사람 수가 적다? (문제 조건 X)
        {
            min = middle + 1;
        }
        else        // 사람수가 크거나 같다(문제 조건 적합)
        {
            if (answer > middle)
                answer = middle;

            max = middle - 1;
        }

    }


    return answer;
}


