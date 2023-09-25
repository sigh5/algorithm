#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <array>
#include <memory.h>

using namespace std;

//int N = 0;
//
//static const int MAX = 501;
//
//array<array<int, MAX>, MAX> arr;
//
//int main()
//{
//	cin >> N;
//
//	int Num = 0;
//
//	for (int i = 1; i <= N; ++i)
//	{
//		for (int j = 1; j < i+1; ++j)
//		{
//			cin>> Num;
//			arr[i][j] = Num;
//		}
//	}
//
//	for (int i = N; i >= 1; --i)
//	{
//		for (int j = 1; j <= i; ++j)
//		{
//			arr[i - 1][j] += max(arr[i][j], arr[i][j + 1]);
//		}
//	}
//
//	cout << arr[1][1];
//
//	
//}

using namespace std;


int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;


    int N = triangle.size();

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < N; ++i)
    {
        int M = triangle[i].size();

        for (int j = 0; j < M; ++j)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i-1][0] + triangle[i - 1][0];
            }
            else if (j == M - 1)
            {
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            else
            {
                dp[i][j] = triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
            }
            
        }
    }

    answer = dp[N - 1][0];

    int ResultSize = triangle[N - 1].size();

    for (int i = 0; i < ResultSize; ++i)
    {
        answer = max(answer, dp[N - 1][i]);
    }


    return answer;
}


int main()
{
    vector<vector<int>> triangle{ {7} ,{3, 8},{8, 1, 0 }, { 2, 7, 4, 4 }, { 4, 5, 2, 6, 5 }};

     cout <<  solution(triangle);

    return 0;
}


