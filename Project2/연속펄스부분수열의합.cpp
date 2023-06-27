#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


vector<int> pulse(vector<int> sequence, int sign)
{
    int Size = sequence.size();
   
    for (int i = 0; i < Size; ++i)
    {
        sequence[i] = sequence[i] * sign;
        sign *= -1;
    }

    return sequence;
}

long long lmax(long long a, long long b)
{
    return a > b ? a : b;
}

long long solution(vector<int> sequence) {
    long long answer = -100'000'000;

    vector<int> seq1 = pulse(sequence, 1);
    vector<int> seq2 = pulse(sequence, -1);

    vector<long long> dpPlus(seq1.size(), 0);
    vector<long long> dpMinus(seq2.size(), 0);

    dpPlus[0] = seq1[0];
    dpMinus[0] = seq2[0];

    for (int i = 1; i < seq1.size(); ++i)
    {
        dpPlus[i] = lmax(dpPlus[i - 1] + static_cast<long long>(seq1[i]), static_cast<long long>(seq1[i]));
        answer = lmax(answer, dpPlus[i]);
    }

    for (int i = 1; i < seq2.size(); ++i)
    {
        dpMinus[i] = lmax(dpMinus[i - 1] + static_cast<long long>(seq2[i]), static_cast<long long>(seq2[i]));
        answer = lmax(answer, dpMinus[i]);
    }

    return answer;
}

int main()
{
    vector<int> sequence{ 2, 3, -6, 1, 3, -1, 2, 4 };
    cout << solution(sequence);
	return 0;
}