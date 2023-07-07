#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <array>
#include <cmath>

using namespace std;

int solution(vector<string> board) {
    int answer = 10000000;
    int boardYSize = board.size();
    int boardXSize = board[0].size();
    int iStartY = 0, iStartX = 0, iGoalY = 0, iGoalX = 0;
    for (int i = 0; i < boardYSize; ++i)
    {
        for (int j = 0; j < boardXSize; ++j)
        {
            if (board[i][j] == 'R')
            {
                iStartY = i;
                iStartX = j;
            }
            else if (board[i][j] == 'G')
            {
                iGoalY = i;
                iGoalX = j;
            }
        }
    }

    array<int, 4> YDir{ -1,1,0,0 };
    array<int, 4> XDir{ 0,0,-1,1 };

    queue<pair<pair<int, int>, int>> q;
    vector<vector<bool>> bVistied(boardYSize, vector<bool>(boardXSize, false));

    q.push({ {iStartY,iStartX},0 });
    bVistied[iStartY][iStartX] = true;

    while (!q.empty())
    {
        int CurY = q.front().first.first;
        int CurX = q.front().first.second;
        int CurCnt = q.front().second;
        q.pop();
        if (CurY == iGoalY && CurX == iGoalX)
        {
            answer = min(answer, CurCnt);
        }

        for (int i = 0; i < 4; ++i)
        {
            int NewY = CurY + YDir[i];
            int NewX = CurX + XDir[i];

            if (0 <= NewY && NewY < boardYSize &&
                0 < NewX && NewX < boardXSize && board[NewY][NewX] != 'D')
            {
                while (true)
                {
                    NewY += YDir[i];
                    NewX += XDir[i];

                    if (!(0 <= NewY && NewY < boardYSize &&
                        0 < NewX && NewX < boardXSize && board[NewY][NewX] != 'D'))
                    {
                        NewY -= YDir[i];
                        NewX -= XDir[i];
                        break;
                    }
                }
                if (bVistied[NewY][NewX])
                    continue;

                bVistied[NewY][NewX] = true;
                q.push({ {NewY,NewX},CurCnt + 1 });
            }
           

        }

    }

    return answer == 10000000 ? -1 : answer;
}


int main()
{
    vector<string> board{ "...D..R",
        ".D.G...",
        "....D.D", 
        "D....D.", 
        "..D...." };

    cout << solution(board);


	return 0;
}

//if (!bVisted[CurY][CurX] && (0 > iNewY || iNewY >= boardYSize ||
//    0 > iNewX || iNewX >= boardXSize || board[iNewY][iNewX] == 'D'))
//{
//    if (CurY == iGoalY && CurX == iGoalX)
//    {
//        answer = min(CurCnt, answer);
//    }
//    else
//    {
//        q.push({ {CurY,CurX},CurCnt + 1 });
//        bVisted[CurY][CurX] = true;
//    }
//
//}