#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    int cur = arrayA[0];
    int arraySize = arrayA.size();
    
    for (int i = 1; i < arraySize; i++) {
        cur = gcd(cur, arrayA[i]);
        if (cur == 1) break;
    }
    if (cur != 1) {
        int i;
        for (i = 0; i < arrayB.size(); i++) {
            if (arrayB[i] % cur == 0) break;
        }
        if (i == arrayB.size()) answer = cur;
    }

     cur = arrayB[0];
     arraySize = arrayB.size();

    for (int i = 1; i < arraySize; i++) {
        cur = gcd(cur, arrayB[i]);
        if (cur == 1) break;
    }
    if (cur != 1) {
        int i;
        for (i = 0; i < arrayA.size(); i++) {
            if (arrayA[i] % cur == 0) break;
        }
        if (i == arrayA.size()) answer = max(cur,answer);
    }
    return answer;
}

int main()
{
    vector<int> arrayA{ 10, 17 };
    vector<int> arrayB{ 5, 20 };


    solution(arrayA, arrayB);

    return 0;
}