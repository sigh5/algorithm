#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
#include <cmath>
using namespace std;

int bfs(const vector<string>& maps, int iStartY, int iStartX)
{
    int MapYSize = maps.size();
    int MapXSize = maps[0].size();

    int answer = 100'000'000;
    queue<pair<pair<int, int>, int>> q;
    q.push({ {iStartY,iStartX },0 });
    
    array<int, 4> YDir{ -1,1,0,0 };
    array<int, 4> XDir{ 0,0,-1,1 };
    vector<vector<bool>> bVisted(MapYSize, vector<bool>(MapXSize, false));
    bVisted[iStartY][iStartX] = true;
    
    while (!q.empty())
    {
        int CurY = q.front().first.first;
        int CurX = q.front().first.second;
        int CurCnt = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NewY = YDir[i] + CurY;
            int NewX = XDir[i] + CurX;

            if (0 <= NewY && NewY < MapYSize &&
                0 <= NewX && NewX < MapXSize &&
                maps[NewY][NewX] != 'X' && bVisted[NewY][NewX] == false)
            {
                bVisted[NewY][NewX] = true;
                q.push({ {NewY,NewX},CurCnt + 1 });
              
                if (maps[NewY][NewX] == 'L')
                {
                    answer = min(CurCnt + 1, answer);
                }
            }
        }
    }

    return answer;
}

int bfsLever(const vector<string>& maps, int iStartY, int iStartX)
{
    int MapYSize = maps.size();
    int MapXSize = maps[0].size();

    int answer = 100'000'000;
    queue<pair<pair<int, int>, int>> q;
    q.push({ {iStartY,iStartX },0 });

    array<int, 4> YDir{ -1,1,0,0 };
    array<int, 4> XDir{ 0,0,-1,1 };
    vector<vector<bool>> bVisted(MapYSize, vector<bool>(MapXSize, false));
    bVisted[iStartY][iStartX] = true;

    while (!q.empty())
    {
        int CurY = q.front().first.first;
        int CurX = q.front().first.second;
        int CurCnt = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int NewY = YDir[i] + CurY;
            int NewX = XDir[i] + CurX;

            if (0 <= NewY && NewY < MapYSize &&
                0 <= NewX && NewX < MapXSize &&
                maps[NewY][NewX] != 'X' && bVisted[NewY][NewX] == false)
            {
                bVisted[NewY][NewX] = true;
                q.push({ {NewY,NewX},CurCnt + 1 });

                if (maps[NewY][NewX] == 'E')
                {
                    answer = min(CurCnt + 1, answer);
                }
            }
        }
    }

    return answer;
}


int solution(vector<string> maps) {
    
    int answer = 0;
    // 레버 먼저 찾고 그다음 출구를 찾는다.

    int iStartY = 0, iStartX = 0;
    int iLeverY = 0, iLeverX = 0;
    int mapYSize = maps.size();
    int mapXSize = maps[0].size();
    
    for (int i = 0; i < mapYSize; ++i)
    {
        for (int j = 0; j < mapXSize; ++j)
        {
            if (maps[i][j] == 'S')
            {
                iStartY = i;
                iStartX = j;
            }
            else if (maps[i][j] == 'L')
            {
                iLeverY = i;
                iLeverX = j;
            }
        }
    }

    int FindLever = bfs(maps, iStartY, iStartX);

    if (FindLever == 100'000'000)
        return -1;

    int FindExit = bfsLever(maps, iLeverY, iLeverX);
    if (FindExit == 100'000'000)
        return -1;

    answer = FindLever + FindExit;

    return answer;
}

int main()
{
    vector<string> maps{ "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" };

    solution(maps);

	return 0;
}