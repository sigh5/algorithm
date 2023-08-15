#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
using namespace std;

#include <string>
#include <vector>

using namespace std;

int answer = 51;

void dfs(string begin, string target, vector<string> words, vector<bool>& bVisted, int cnt)
{
    for (int i = 0; i < words.size(); ++i)
    {
        int count = 0;

        for (int j = 0; j < words[i].size(); ++j)
        {
            if (!bVisted[i] && words[i][j] != begin[j])
            {
                ++count;        // 무조건 1개여야한다. 1개만 바꾸니까

            }
        }

        if (count == 1)
        {
            if (words[i] == target)
            {
                if (answer > cnt + 1)
                    answer = cnt + 1;

                return;
            }
            else
            {
                bVisted[i] = true;
                dfs(words[i], target, words, bVisted, cnt + 1);
                bVisted[i] = false;
            }




        }

    }


}


int solution(string begin, string target, vector<string> words) {

    vector<bool> bVisted(words.size(), false);

    dfs(begin, target, words, bVisted, 0);

    if (answer == 51)
        return 0;
    else
        return answer;
}


int main()
{
    vector<string> computers{ "hot", "dot", "dog", "lot", "log", "cog" };


    cout << solution("hit"s,"cog"s ,computers);

    return 0;
}