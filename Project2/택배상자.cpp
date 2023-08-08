#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;

    stack<int> stack;
    int OrderSize = order.size();

    int idx = 0;
    int ContainerNum = 1;
    
    while(ContainerNum <= OrderSize)
    {
        if (order[idx] != ContainerNum)
        {
            if (!stack.empty() && stack.top() == order[idx])
            {
                ++answer, ++idx;
 
                stack.pop();
                continue;
            }
           
            stack.push(ContainerNum);
        }
        else
        {
            ++answer;
            idx++;   
        }

        ++ContainerNum;
    }
    

    while (!stack.empty())
    {
        if (order[idx] == stack.top())
        {
            stack.pop();
            ++idx, ++answer;
        }
        else
            break;
    }

    



    return answer;
}

int main()
{
    vector<int> order{ 3,2,1,4,5 };

    cout << solution(order);


    return 0;
}
