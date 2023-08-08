#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;


int solution(vector<int> elements) {
    int answer = 0;
    int elementsSize = elements.size();     // 1 ~ elementsSize 길이까지의 연속부분수열을 만들 수 있다.
    
    set<int> valueSet;

    int length = 1;
    while (length <= elementsSize)
    {
       
        for (int i = 0; i < elementsSize; ++i)
        {
            int Sum = 0;
            for (int j = i; j < i + length; ++j)
            {
                if (j >= elementsSize)
                {
                    Sum += elements[j - elementsSize];
                }
                else
                {
                    Sum += elements[j];
                }
            }
            valueSet.insert(Sum);
        }


        ++length;
    }


    answer = valueSet.size();

    return answer;
}

int main()
{

    vector<int> elements{7,9,1,1,4};

    cout << solution(elements);

	return 0;
}