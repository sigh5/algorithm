#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    sort(data.begin(), data.end(), [&](auto& data0, auto& data1)
        {
            if (data0[col - 1] == data1[col - 1])
            {
                return data0[0] > data1[0];
            }
            return data0[col - 1] < data1[col - 1];
        });

    vector<int> RowSum;
    int sum = 0;
    int tupleSize = data[0].size();
    for (int i = row_begin - 1; i <= row_end - 1; ++i)
    {
        for (int j = 0; j < tupleSize; ++j)
        {
            sum += data[i][j] % i+1;
        }
        RowSum.push_back(sum);
    }

    int RowSumSize = RowSum.size();
    answer = RowSum[0];
    for (int i = 1; i < RowSumSize; ++i)
    {
        answer = answer ^ RowSum[i];
    }


    return answer;
}

int main()
{ 

    vector<vector<int>> data{ {2, 2, 6} ,{1, 5, 10},{4, 2, 9},{3, 8, 3} };

    solution(data, 2, 2, 3);

    return 0;
}