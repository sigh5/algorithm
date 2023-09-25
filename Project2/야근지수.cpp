#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long answer = 0;




long long solution(int n, vector<int> works) {
    

    int workSize = works.size();

    sort(works.begin(), works.end());
    
    while (n > 0 && works[0] != 0)
    {
        int cnt = 1;
        int Sour = 0;
        int index = 0;

        for (int i = workSize - 1; i >= 0; --i)
        {
            if (i > 0 && works[i - 1] == works[i])
            {
                cnt++;
            }
            else
            {
                Sour = works[i] - works[i - 1];
                index = i;
                break;
            }
        }

        if (n / cnt >= Sour)
        {
            for (int i = 0; i < cnt; ++i)
            {
                works[index + i] -= Sour;
              
            }
            n -= cnt*Sour;
        }
        else
        {
            for (int i = 0; i < cnt; ++i)
            {
                works[index + i] -= n / cnt;
            }
            for (int i = 0; i < n % cnt; ++i)
            {
                --works[index + i];
            }
            n = 0;
        }

    }








    return answer;
}


int main()
{

    vector<int> works{ 4, 3, 3 };

    solution(4, works);

	return 0;
}