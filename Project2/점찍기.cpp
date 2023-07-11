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
    long long bk = d - (d % k); // 현재 인덱스가 0일때 bk를 곱해서 나올 수 있는 최대 값을 구함
                       // 5 % 3 이면  몫 1: 나머지 2 니까       a == 0 일때최대값을 찾는다.
    long long dDouble = d * d;
    while (ak <= d)
    {
        answer += (bk / k) + 1;
        ak += k;   // 1 * k 씩 증가하니까 k를 더한다.
 
        while (dDouble < (ak * ak) + (bk * bk) && bk >0)
        {
            bk -= k;    // 1 * k 씩 증가하니까 k를 더한다.
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