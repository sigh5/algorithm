#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    // 무적권 사용법
    // 1. 자기보다 몰려오는 적의 수가 많거나 같은 경우
    // 2. 평균값보다 높은 경우
    // 3. 
    priority_queue<int> pq;
    int enemySize = enemy.size();
    int i = 0;
    for (; i < enemySize; ++i)
    {
        if (n >= enemy[i])
        {
            n -= enemy[i];
            pq.push(enemy[i]);
        }
        else
        {
            if (k == 0)
                break;
            if (!pq.empty() && (pq.top() > enemy[i]))
            {
                n += pq.top();
                pq.pop();
                n -= enemy[i];
                pq.push(enemy[i]);
            }

        }
        --k;   
     
    }


    return i;
}

int main()
{
    vector<int> enemy{ 4, 2, 4, 5, 3, 3, 1 };

    solution(7, 3, enemy);

    return 0;
}