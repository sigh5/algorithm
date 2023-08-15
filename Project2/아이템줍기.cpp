#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int world[52][52];


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;
    //1. ������ ������ �� �ϴ� �ٱ��� �������� ���¹� 
    //
    // 1. �ϴ� ������ ������ ��ü �ʺ� 1�� ä���
    // 2. ��ģ ������ ������� 0 ���ιٲ۴�.

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