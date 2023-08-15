#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int world[52][52];


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;
    //1. 도형이 겹쳤을 때 일단 바깥쪽 테투리를 따는법 
    //
    // 1. 일단 도형이 들어오면 전체 너비를 1로 채운다
    // 2. 겹친 도형이 있을경우 0 으로바꾼다.

    int rectangleSize = rectangle.size();

    for (int i = 0; i < rectangleSize; ++i)
    {
        for (int j = rectangle[i][0]; j < rectangle[i][2]; ++j)
        {
            for (int q = rectangle[i][1]; q < rectangle[i][3]; ++q)
            {
                world[j][q] += 1;
            }
        }
    }


    for (int i = 0; i < rectangleSize; ++i)
    {
        for (int j = rectangle[i][0]; j < rectangle[i][2]; ++j)
        {
            for (int q = rectangle[i][1]; q < rectangle[i][3]; ++q)
            {
                if (world[j][q] >= 2)
                    world[j][q] = 0;
            }
        }
    }

  
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << world[i][j] << " ";
        }
        puts("\n");
    }



    return answer;
}


int main()
{
    vector<vector<int>> rectangle{ {1,1,7,4} ,{3,2,5,5},{4,3,6,9},{2,6,8,8} };

    solution(rectangle, 1, 3, 7, 8);


    return 0;
}