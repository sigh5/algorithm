#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int world[101][101];
int answer = 100'000'000;

int xDir[4] = { -1,1,0,0 };
int yDir[4] = { 0,0,-1,1 };

void dfs(int startX, int startY, int goalX, int goalY, int count)
{
    if (startX == goalX && startY == goalY)
    {
        answer = min(count, answer);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int NewX = xDir[i] + startX;
        int NewY = yDir[i] + startY;


        if (NewY >= 0 && NewY <= 100 &&
            NewX >= 0 && NewX <= 100 &&
            world[NewX][NewY] == 7)
        {
            world[NewX][NewY] = 0;
            dfs(NewX, NewY, goalX, goalY, count + 1);
            world[NewX][NewY] = 7;
        }
    }

}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    //1. 도형이 겹쳤을 때 일단 바깥쪽 테투리를 따는법 
    //
    // 1. 일단 도형이 들어오면 전체 너비를 1로 채운다
    // 2. 겹친 도형이 있을경우 0 으로바꾼다.

    int rectangleSize = rectangle.size();

    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;





    for (int i = 0; i < rectangleSize; ++i)
    {
        for (int j = rectangle[i][0] *2 ; j <= rectangle[i][2] *2; ++j)
        {
            for (int q = rectangle[i][1]*2; q <= rectangle[i][3]*2; ++q)
            {
                world[j][q] = 7;
            }
        }
    }


    for (int i = 0; i < rectangleSize; ++i)
    {
        for (int j = rectangle[i][0]* 2 +1; j <= rectangle[i][2] *2 -1; ++j)
        {
            for (int q = rectangle[i][1]*2+1; q <= rectangle[i][3]*2-1; ++q)
            {
                
                    world[j][q] = 0;
            }
        }
    }

  
    world[characterX][characterY] = 1;
    dfs(characterX, characterY, itemX, itemY, 0);

    return static_cast<int>(answer/2);
}


int main()
{
    vector<vector<int>> rectangle{ {1,1,7,4} ,{3,2,5,5},{4,3,6,9},{2,6,8,8} };

    cout << solution(rectangle, 1, 3, 7, 8);


    return 0;
}