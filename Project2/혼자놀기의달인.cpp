#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>


using namespace std;




int solution(vector<int> cards) 
{
    int answer = 0;

    int cardSize = cards.size();
    vector<bool> CardOpen(cardSize, false);
    vector<int> Groups(cardSize,0);

    int Next_Card = cards[0];
    int Cur_Index = 0;
    
    for(int i=0; i<cardSize; ++i)
    {
        if (CardOpen[i] == true)
            continue;
    
        Next_Card = cards[i]-1;
        while (true)
        {
            if (!CardOpen[Next_Card])
            {
                CardOpen[Next_Card] = true;
                ++Groups[Cur_Index];
                Next_Card = cards[Next_Card] - 1;
            }
            else
            {
                ++Cur_Index;
                break;
            }
        }

      
    }

    sort(Groups.begin(), Groups.end(), [](int& a, int& b)
        {
            return a > b;
        });
   

    answer = Groups[0] * Groups[1];
    return answer;
}


int main()
{
    vector<int> cards{ 8,6,3,7,2,5,1,4 };
    cout << solution(cards);

    return 0;
}


//vector<int> Box2VistedIndex;
//int MaxBox2Num = -1;
//
//for (int i = 0; i < cardSize; ++i)
//{
//    index = cards[i];
//    if (!CardOpen[index - 1])
//    {
//        while (true)
//        {
//            if (!CardOpen[index - 1])
//            {
//                CardOpen[index - 1] = true;
//                Box2.push_back(cards[index - 1]);
//                index = cards[index - 1];
//                Box2VistedIndex.push_back(index - 1);
//            }
//            else
//            {
//                break;
//            }
//        }
//
//        for (int i = 0; i < Box2VistedIndex.size(); ++i)
//        {
//            CardOpen[Box2VistedIndex[i]] = false;
//        }
//
//        MaxBox2Num = max(MaxBox2Num, (int)Box2.size());
//        Box2.clear();
//        Box2VistedIndex.clear();
//    }
//}
//
//if (MaxBox2Num == -1)
//answer = 0;
//else
//answer = MaxBox2Num * Box1.size();
//
