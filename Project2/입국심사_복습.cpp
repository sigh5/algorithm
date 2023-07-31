#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {


    sort(times.begin(), times.end());

    long long min = 1;  // �ɸ��� �ð� 1�� ��� ������� �ּҷ� ������ �ð�
    long long max = (long long)times[times.size() - 1] * n; // ��� ������� �ִ�� ������ �ð�

    long long answer = max;


    while (min <= max)
    {
        long long middle = (min + max) / 2; // �߰���

        long long Cnt = 0; // �Ա��㰡 ���� ������� ��

        for (int i = 0; i < times.size(); ++i)
        {
            // �� �ð����� ó���� �� �ִ� ��� ��
            Cnt += middle / times[i];
        }

        if (Cnt < n) // ��� ���� ����? (���� ���� X)
        {
            min = middle + 1;
        }
        else        // ������� ũ�ų� ����(���� ���� ����)
        {
            if (answer > middle)
                answer = middle;

            max = middle - 1;
        }

    }


    return answer;
}


