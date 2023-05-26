#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main()
{
    vector<string> participant{ "mislav"s, "stanko"s, "mislav"s, "ana"s };
    vector<string> completion{ "stanko"s, "ana"s, "mislav"s };
    string answer = "";
    unordered_map<string,int> paricipantSet;
    
    for (auto Names : participant)
    {
        paricipantSet[Names]++;
    }

    for (auto Names : completion)
    {
        paricipantSet[Names]--;
    }

    for (auto Names : participant)
    {
        if (paricipantSet[Names] == 1)
        {
            answer = Names;
            break;
        }
    }


    cout << answer;
    return 0;
}