#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> s;  // �ε��� ���� �ִ´�. �ε������� �ð�
    int PriveVecSize = prices.size();

    for (int i = 0; i < PriveVecSize; ++i)
    {
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        answer[s.top()] = PriveVecSize - s.top() - 1;
        s.pop();
    }


    return answer;
}

int main()
{
    vector<int> prices{ 1, 2, 3, 2, 3 };

    solution(prices);

	return 0;
}