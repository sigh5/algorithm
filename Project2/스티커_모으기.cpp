#include <iostream>
#include <list>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;


int solution(vector<int> sticker)
{
    int answer = 0;
    int stickerSize = sticker.size();
    int PrevResult = 0;


    vector<int> dp(stickerSize, 0);

    // 첫번째 스티커를 뜯었을 경우 
    dp[0] = sticker[0];
    dp[1] = 0;

    for (int i = 2; i < stickerSize; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    }

    dp[stickerSize - 1] = dp[stickerSize - 2]; // 마지막 스티커는 뜯을수 없기 때문에


    PrevResult = *max_element(dp.begin(), dp.end());

    dp[0] = 0;
    dp[1] = sticker[1];
    for (int i = 2; i < stickerSize; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    }

    answer = max(PrevResult, *max_element(dp.begin(), dp.end());

    return answer;
}

int main()
{                       //0  1  2  3   4  5  6  7 
    vector<int> sticker{ 14, 6, 5, 11, 3, 9, 2, 10 };

    solution(sticker);

    return 0;
}