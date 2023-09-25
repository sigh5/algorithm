#include <iostream>
#include <string>
#include <list>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;



int solution(vector<int> A, vector<int> B) {   

    int answer = 0;

    int ASize = A.size();
    

    sort(B.begin(), B.end());
    sort(A.begin(), A.end());
    
    int idx = 0;
    
    for (int i = 0; i < ASize; ++i)
    {
        if (B[i] > A[idx])
        {
            answer++;
            ++idx;
        }
    }

   
    return answer;
}



int main()
{
    vector<int> A{ 5,1,3,7 }, vector<int> B{ 2,2,6,8 };
    solution(A, B);
    return 0;
}