#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    queue<pair<string,int>> q;
        
    for (int i = 0; i < words.size(); ++i)
    {
        int iCount = 0;
        for (int j = 0; j < begin.size(); ++j)
        {
            if (words[i][j] == begin[j])
                iCount++;
        }

        if(iCount == begin.size()-1)
            q.push({words[i],i });
    }
  
   
    if (q.size() == 0)
        return 0;

    vector<bool> bVisted(words.size(), false);
    vector<int> iVisteCount(words.size(), 0);
    iVisteCount[q.front().second] = 1;
    bVisted[q.front().second] = true;
    bool bOk = false;
    while (!q.empty())
    {
        string curStr = q.front().first;
        int CurVisted = q.front().second;
        q.pop();

        if (curStr == target)
        {
            answer = CurVisted;
            bOk = true;
            break;
        }

        for (int i = 0; i < words.size(); ++i)
        {
            int iCount = 0;
            
            if (bVisted[i] == true)
            {
                continue;
            }
            for (int j = 0; j < curStr.size(); ++j)
            {
                if (words[i][j] == curStr[j])
                    iCount++;
            }

            if (iCount == curStr.size() - 1)
            {
                bVisted[i] = true;
                q.push({ words[i],i });
                
               
                iVisteCount[i] = iVisteCount[CurVisted] + 1;
            }
        }
    }



    if (bOk == false)
        return 0;

    return iVisteCount[answer];
}

int main()
{
    vector<string> words{ "hot", "dot", "dog", "lot", "log" };

    solution("hit", "cog", words);


    return 0;
}