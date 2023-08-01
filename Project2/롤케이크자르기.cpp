#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solution(vector<int> topping) 
{
    // ���ҵ��� ���Ļ����϶� �̺�Ž���� ����ؾ��Ѵ�.
    int answer = 0;
    int toppingSize = topping.size();

    unordered_map<int,int> Alltopping;
   

    for (int i = 0; i < toppingSize; ++i)
    {
        Alltopping[topping[i]]++;
    }

    unordered_map<int, int> Use_topping;

    for (int i = 0; i < toppingSize; ++i)
    {
        if (Alltopping[topping[i]] >= 1)
        {
            Alltopping[topping[i]]--;


            if (Alltopping[topping[i]] == 0)
            {
                Alltopping.erase(topping[i]);
            }

            Use_topping[topping[i]] ++;
        }

        if (Use_topping.size() == Alltopping.size())
            ++answer;
        
    }

    
    return answer;
}

int main()
{
    vector<int> topping{ 1, 2, 1, 3, 1, 4, 1, 2 };

    solution(topping);
}