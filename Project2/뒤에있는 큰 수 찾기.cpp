#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
using namespace std;

//array<int, 1'000'000> dp;
//
//vector<int> solution(vector<int> numbers) {
//    vector<int> answer;
//
//    // ������ ���ؼ� �̺�Ž���� ����
//    // �׷��� ���°� �������Ͷ� dp�ε� dp�� �տ��� �ϹǷ� dp�� �Ұ�
//
//    int numbersSize = numbers.size();
//
//    dp[numbersSize-1] = -1;
//
//
//    for (int i = numbersSize-1; i > 0; --i)
//    {
//        if (numbers[i-1] >= numbers[i])
//        {
//            if (numbers[i-1] >= dp[i])
//                dp[i-1] = -1;
//            else
//                dp[i-1] = dp[i];
//        }
//        else
//        {
//            dp[i-1] = numbers[i];
//        }
//
//    }
//
//    for (int i = 0; i < numbersSize; ++i)
//    {
//        answer.push_back(dp[i]);
//    }
//
//    return answer;
//}

class CBasa : Interface
{

    private::
};


int main()
{
    vector<int> numbers{ 2, 3, 3, 5 };
    solution(numbers);
    return 0;
}