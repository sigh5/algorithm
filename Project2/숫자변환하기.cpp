#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int bfs(int x, int y, int n)
{
    int answer = 0;
    queue<int> q;
    q.push(y);

    vector<bool> bVisted(y, false);

    while (!q.empty())
    {
        int CurQ = q.front();
        q.pop();

        if (CurQ % 3 == 0 && !bVisted[CurQ / 3])
        {
            q.push(CurQ / 3);
            bVisted[CurQ / 3] = true;
        }
        else if (CurQ % 2 == 0 && !bVisted[CurQ / 2])
        {
            q.push(CurQ / 2);
            bVisted[CurQ / 2] = true;
        }
        else if (!bVisted[CurQ - n])
        {
            q.push(CurQ - n);
            bVisted[CurQ - n] = true;
        }
        ++answer;
    }

    return answer;
}

int solution(int x, int y, int n) {
    int answer = 0;

    if (x == y)
        return 0;

    answer = bfs(x, y, n);

    if (answer == 0)
        return -1;

    return answer;
}

int main()
{
    solution(10, 40, 5);

    std::vector<bool> b;

    b.flip();



}