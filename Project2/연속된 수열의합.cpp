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
        int sum = sequence[0]; // �κ� ������ ��
        int subLen = sequence.size() + 1; // �κ� ������ ����
        pair<int, int> result; // �κ� ������ ���� �ε����� ������ �ε����� ���� ��ü

        while (start <= end && end < sequence.size()) {
            if (sum < k) sum += sequence[++end];
            else if (sum == k) {
                if (end - start + 1 < subLen) { // ���̰� �� ª�� �����̸�
                    subLen = end - start + 1;
                    result = { start, end };
                }
                else if (end - start + 1 == subLen) {
                    if (start < result.first) { // ���� �ε����� �� ������
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