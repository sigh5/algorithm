#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>


using namespace std;
vector<string> answer;
bool bVisted[10001] = { false, };
int  UseCnt = 0;
bool ReadyAnswer = false;

void dfs(string startStr, const vector<vector<string>>& tickets)
{
    if (UseCnt == tickets.size())
    {
        ReadyAnswer = true;
    }

    answer.push_back(startStr);

    for (int i = 0; i < tickets.size(); ++i)
    {
        if (tickets[i][0] == startStr && !bVisted[i])
        {
            bVisted[i] = true;
            dfs(tickets[i][1], tickets);
            ++UseCnt;
            if (ReadyAnswer == false)
            {
                bVisted[i] = false;

                answer.pop_back();
            }
        }
    }

}


vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end());

    dfs("ICN", tickets);


    return answer;
}

int main()
{
    vector<vector<string>> tickets{ {"ICN", "SFO"} ,{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"}, {"ATL", "SFO"} };
    
    solution(tickets);

    return 0;
}