#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[60001];



int solution(int n)
{
    int answer = 0;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; ++i)
    {
        
        dp[i] = (dp[i-1] + dp[i - 2] ) % 1'000'000'007;
        

    }
    
    answer = dp[n] ;

    
    return answer;
}
int main()
{

    solution(4);

	return 0;
}