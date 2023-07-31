#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


long long solution(int _k, int _d)
{
    long long answer = 0;

    long long k = _k;
    long long d = _d;
    long long ak = 0;
    long long bk = d - (d % k); // ���� �ε����� 0�϶� bk�� ���ؼ� ���� �� �ִ� �ִ� ���� ����
                       // 5 % 3 �̸�  �� 1: ������ 2 �ϱ�       a == 0 �϶��ִ밪�� ã�´�.
    long long dDouble = d * d;
    while (ak <= d)
    {
        answer += (bk / k) + 1;
        ak += k;   // 1 * k �� �����ϴϱ� k�� ���Ѵ�.
 
        while (dDouble < (ak * ak) + (bk * bk) && bk >0)
        {
            bk -= k;    // 1 * k �� �����ϴϱ� k�� ���Ѵ�.
        }
    }




    return answer;
}

int main()
{
    cout << solution(1, 5);

	return 0;
}

//while (true)
//{
//    int CurSum = iSum;
//    if (j_Idx == 0)
//        CurSum = CurSum / k;
//    else
//        CurSum = CurSum / (j_Idx * k);
//
//    if (CurSum < 0)
//        break;
//
//    ++j_Idx;
//    ++answer;
//}