#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int Index = 0;
    int sum = 0;

    while (true)
    {

        if (Index == truck_weights.size()) // 마지막 트럭일때
        {
            answer += bridge_length;
            break;
        }

        ++answer;

        int CurWeight = truck_weights[Index];

        if (q.size() == bridge_length)
        {
            sum -= q.front();
            q.pop();
        }

        if (sum + CurWeight <= weight)
        {
            sum += CurWeight;
            q.push(sum);
            Index++;

        }
        else
            q.push(0);
    }

    return answer;
}


int main()
{
    vector<int> truck_weights{ 7,4,5,6 };
    int a=  solution(2, 10, truck_weights);

    return 0;
}