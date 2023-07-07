#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int iEndIndex = -1;

bool dfs(const vector<int>& sequence, int StartIndex, int iSum, int k)
{
    if (StartIndex >= sequence.size())
        return false;

    iSum += sequence[StartIndex];

    if (iSum == k)
    {
        iEndIndex = StartIndex;
        return true;
    }
    else if (iSum < k)
        dfs(sequence, StartIndex + 1, iSum, k);
    else if(iSum >k)
        return false;
    
}

vector<int> solution(vector<int> sequence, int k) {

        int start = 0, end = 0;
        int sum = sequence[0]; // 부분 수열의 합
        int subLen = sequence.size() + 1; // 부분 수열의 길이
        pair<int, int> result; // 부분 수열의 시작 인덱스와 마지막 인덱스를 담은 객체

        while (start <= end && end < sequence.size()) {
            if (sum < k) sum += sequence[++end];
            else if (sum == k) {
                if (end - start + 1 < subLen) { // 길이가 더 짧은 수열이면
                    subLen = end - start + 1;
                    result = { start, end };
                }
                else if (end - start + 1 == subLen) {
                    if (start < result.first) { // 시작 인덱스가 더 작으면
                        result = { start, end };
                    }
                }

                sum -= sequence[start++];
            }
            else sum -= sequence[start++];
        }

        return { result.first, result.second };
    }
}

int main()
{
    vector<int> sequence{ 1, 1, 1, 2, 3, 4, 5 };
    int k = 5;

    solution(sequence, k);


    return 0;
}