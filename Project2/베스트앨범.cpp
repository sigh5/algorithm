#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cmath>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> musicPlay;
    map<string, map<int, int>> Map; // index , Plays
    for (int i = 0; i < genres.size(); ++i)
    {
        musicPlay[genres[i]] += plays[i];
        Map[genres[i]].insert({  i,plays[i] });
    }

    while (musicPlay.size() > 0)
    {
        int imax = 0;
        string GenresStr = "";
        for (auto MaxPlay : musicPlay)
        {
            if (imax < MaxPlay.second)
            {
                imax = MaxPlay.second;
                GenresStr = MaxPlay.first;
            }
        }

        for (int i = 0; i < 2; ++i)
        {
            int MuicsMax = 0;
            int iDx = -1;
            for (auto MaxPlayIndex : Map[GenresStr])
            {
                if (MuicsMax < MaxPlayIndex.second)
                {
                    MuicsMax = MaxPlayIndex.second;
                    iDx = MaxPlayIndex.first;
                }
            }

            if (iDx == -1)
                break;

            answer.push_back(iDx);
            Map[GenresStr].erase(iDx);

        }

        musicPlay.erase(GenresStr);
    }

    return answer;
}

int main()
{
    vector<string> genres{ "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays{ 800, 600, 150, 800, 2500 };
    solution(genres,plays);

    return 0;
}