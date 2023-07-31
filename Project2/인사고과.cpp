#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool IsCmp(const vector<int>& a, const vector<int>& b)
{
    return a[0] < b[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 100'001;

    int PlayerScoreX = scores[0][0];
    int PlayerScoreY = scores[0][1];
    int PlayerScoreSum = PlayerScoreX + PlayerScoreY;
    int scoresSize = scores.size();

    sort(scores.begin(), scores.end(), IsCmp);


    for (int i = 0; i < scores.size(); ++i)
    {
        bool iSDel = false;
        for (int j = i + 1; j < scores.size(); ++j)
        {
            if (scores[i][0] == scores[j][0])
                continue;
            if (scores[i][1] < scores[j][1])
            {
                iSDel = true;
                scores.erase(scores.begin() + i);
                break;
            }
        }
        if (iSDel)
            i--;
    }

    sort(scores.begin(), scores.end(), [](auto& a, auto& b)
        {
            return a[0] + a[1] > b[0] + b[1];
        });


    int Index = 0;
    int PrevSum = scores[0][0] + scores[0][1];
    if (PrevSum == PlayerScoreX + PlayerScoreY)
        return 1;

    for (int i = 0; i < scores.size(); ++i)
    {
        if (PrevSum != scores[i][0] + scores[i][1])
        {
            Index = i;
            if (PlayerScoreX == scores[i][0] && scores[i][1] == PlayerScoreY)
            {
                answer = Index;
                break;
            }
        }
        else
        {
            Index = i + 1;
            if (PlayerScoreX == scores[i][0] && scores[i][i] == PlayerScoreY)
            {
                answer = Index;
                break;
            }
        }

        PrevSum = scores[i][0] + scores[i][1];
    }

    answer += 1;

    return answer;
}

int main()
{
	vector<vector<int>> scores{ {4, 0},{2, 3},{4, 4},{2, 6} };

	solution(scores);
	return 0;
}



