#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <array>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    // 0 벽 , 1 갈 수 있는곳
    array<int, 4> yDir{ -1,1,0,0 };
    array<int, 4> xDir{ 0,0,-1,1 };
    
    int LastY = maps.size()-1;
    int LastX = maps[0].size()-1;

    int iCount = 0;

    vector<vector<int> > bVistedData;

    bVistedData.resize(maps.size());

    for (int i = 0; i < maps.size(); ++i)
    {
        bVistedData[i].resize(maps[0].size());
    }
    

    queue<pair<int, int>> q;

    q.push({ 0, 0 });
    bVistedData[0][0] = 1;
    
    while (!q.empty())
    {
        int iCurY = q.front().first;
        int iCurX = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int iNewY = iCurY + yDir[i];
            int iNewX = iCurX + xDir[i];

            if (iNewY >= 0 && iNewY <= LastY &&
                iNewX >= 0 && iNewX <= LastX && maps[iNewY][iNewX] == 1)
            {
                bVistedData[iNewY][iNewX] = bVistedData[iCurY][iCurX] + 1;
                maps[iNewY][iNewX] = 0;
                q.push({ iNewY,iNewX });
            }

        }

    }

    if (bVistedData[LastY][LastX] == 0)
        return -1;


    return bVistedData[LastY][LastX];
}


int foo(int a)
{
    return 0;
}

double foo(int a)
{
    return 0.0;
}

int main()
{
    
    vector<vector<int> > maps{ {1,0,1,1,1} , {1,0,1,0,1} , {1,0,1,1,1} , {1,1,1,0,1}, {0,0,0,0,1} };
    
   // cout << solution(maps);
    
    foo(0.0);


	return 0;
}