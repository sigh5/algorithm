#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> numVec;
    string buffer = "";
    stringstream sss(s);
    char delim = ' ';
    while (getline(sss, buffer, delim))
    {
        numVec.push_back(stoi(buffer));
    }
    sort(numVec.begin(), numVec.end());

    string Temp = to_string(numVec[0]);


    return answer;
}

int main()
{

    solution("1 2 3 4");

    return 0;
}