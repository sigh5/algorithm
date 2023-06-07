#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> times) {
    
    sort(times.begin(), times.end());
    // �ð��� �������� �ξ��� �� �ּ� ��� 1�йۿ� �Ȱɸ���
    long long min = 1;
    // �ð��� �������� �ξ��� �� �ִ�
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

        if (cnt < n) // ����� n ���� ����
        {
            min = middle + 1;
        }
        else  // ����� n���� ���ų� ���� 
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