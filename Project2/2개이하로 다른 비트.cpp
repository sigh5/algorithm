#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <limits>
using namespace std;


vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
   
    // ¦���� ������ 1�������̰�  Ȧ���� ��Ʈ�� 1�����Ѵ�.
   
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] % 2 == 0)
        {
            answer.push_back(numbers[i] + 1);
        }
        else
        {
            long long bit = 1;
            while (true)
            {
                if ((numbers[i] & bit)==false)
                {
                    break;
                }
                bit *= 2;
            }
            bit = bit / 2;
            
        }
    }


 

    
    return answer;
}



int main()
{
    vector<long long> numbers{ 2,7 };

  solution(numbers);

	return 0;
}