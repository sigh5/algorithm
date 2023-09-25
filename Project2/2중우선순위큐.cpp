#include <iostream>
#include <string>
#include <list>
#include <array>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int opSize = operations.size();
    set<int> pq;

    for (int i = 0; i < opSize; ++i)
    {
        char sz_Op = operations[i][0];

        if (sz_Op == 'I')
        {
            string Sour = "";
            for (int j = 1; j < operations[i].size(); ++j)
            {
                Sour += operations[i][j];
            }

            int ConvertValue = stoi(Sour);

            pq.insert(ConvertValue);
        }
        else if (!pq.empty() && sz_Op == 'D')
        {
            if (operations[i][2] == '-')
            {
                pq.erase(pq.begin());
              
            }
            else
            {
               
                pq.erase(--pq.end());
            }
        }

    }


    if (!pq.empty())
    {
        answer.push_back(*(--pq.end()));
         answer.push_back(*pq.begin());
        
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
   


    return answer;
}
int main()
{
    vector<string> operation{ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };

    solution(operation);

	return 0;
}