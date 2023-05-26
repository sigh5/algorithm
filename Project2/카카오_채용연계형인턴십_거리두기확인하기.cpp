#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool WidthCheck(vector<string> place)
{
    string placestr;

    for (int i = 0; i < 5; ++i)
    {
        placestr += place[i];
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int Index = (i * 5) + j;

            if (j < 4 && placestr[Index] == 'P' && placestr[Index + 1] == 'P')
                return false;
            else if (j < 3 && placestr[Index] == 'P' && placestr[Index + 2] == 'P')
            {
                if (placestr[Index + 1] == 'X')
                    continue;
                
                return false;
            }
            else
                continue;
        }
    }
    return true;
}

bool HeightCheck(vector<string> place)
{
    string placestr = place[0];

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int Index = (j * 5) + i;

            if (j < 4 && placestr[Index] == 'P' && placestr[Index + 5] == 'P')
                return false;
            else if (j < 3 && placestr[Index] == 'P' && placestr[Index + 10] == 'P')
            {
                if (placestr[Index + 5] == 'X')
                    continue;
                return false;
            }
            else
                continue;
        }
    }
    return true;
}

bool LeftToRight_Diagonal(vector<string> place)
{
    string placestr = place[0];

    // 6씩증가

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int Index = (i * 5) + j;

            if (Index + 6 < 25 && j != 4 &&
                placestr[Index] == 'P' && placestr[Index + 6] == 'P')
            {
                if (placestr[Index + 1] == 'X' && placestr[Index + 5] == 'X')
                {
                    continue;
                }
                return false;
            }
        }
    }
    return true;
}

bool RightToLeft_Diagonal(vector<string> place)
{
    string placestr = place[0];

    // 4씩 증가

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int Index = (i * 5) + j;

            if (j != 0 && Index + 4 < 25 &&
                placestr[Index] == 'P' && placestr[Index + 4] == 'P')
            {
                if (placestr[Index - 1] == 'X' && placestr[Index + 5] == 'X')
                {
                    continue;
                }
                return false;
            }
        }
    }
    return true;
}

int MySolution(vector<string> place)
{
   bool b = WidthCheck(place);
   if (b == false)
       return 0;
   b = HeightCheck(place);
   if (b == false)
       return 0;
   b = LeftToRight_Diagonal(place);
   if (b == false)
       return 0;
   b = RightToLeft_Diagonal(place);
   if (b == false)
       return 0;
     


    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (auto place : places)
    {
        answer.push_back(MySolution(place));
    }

    return answer;
}

int main()
{
    vector<vector<string>> places;

    vector<string> InputData;

    string data;

    for (int t = 0; t < 1; ++t)
    {
        for (int i = 0; i < 5; ++i)
        {
            cin >> data;
            InputData.push_back(data);

        }
         

         places.push_back(InputData);
            
        
    }
   
    solution(places);

    return 0;
}