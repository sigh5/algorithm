#include <iostream>
#define n 4
#define r 3
using namespace std;

int pArr[r] = { 0, };
bool check[n + 1] = { false, };

void printArray()
{  
    for (int i = 0; i < r; ++i)
    {
        cout << pArr[i] << " ";    
    }
    puts("-----------------");
}

void permutation(int depth) {
    if (depth == r) {
        printArray();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            check[i] = true;
            pArr[depth] = i;
            permutation(depth + 1);
            check[i] = false;
        }
    }
}

int main(void) {
    cout << "순열 (순서o, 중복x)" << endl;
    permutation(0);

    return 0;
}