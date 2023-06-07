#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> times) {
    
    sort(times.begin(), times.end());
    // 시간을 기준으로 두었을 때 최소 모두 1분밖에 안걸릴때
    long long min = 1;
    // 시간을 기준으로 두었을 때 최대
    long long max = long long((*(times.end() - 1)) * n);
    long long answer = max;
    

    while (min <= max)
    {
        long long middle = (min + max) / 2;
        long long cnt = 0;

        for (int i = 0; i < times.size(); ++i)
        {
            cnt += middle / times[i];
        }

        if (cnt < n) // 사람이 n 보다 적다
        {
            min = middle + 1;
        }
        else  // 사람이 n보다 많거나 같다 
        {
            if(middle <= max)
                answer = middle;

            max = middle - 1;
        }

    }


    return answer;
}

int main()
{
    vector<int> times{ 7,10 };
    cout << solution(6, times);

	return 0;
}