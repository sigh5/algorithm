#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//float ChangeNum(int num)
//{
//    float fResult = 0.f;
//
//    if (10 > num)
//    {
//        fResult = num + 0.005f;
//    }
//    else if (100 > num && num >= 10)
//    {
//        float Ten = num / 10;
//        float One = num - int(10 * Ten);
//        fResult = Ten + (One * 0.1f);
//    }
//    else if (1000 > num && num >= 100)
//    {
//        float Back = num / 100;
//        float Ten = (num - Back * 100) / 10;
//        float One = (num - Back * 100) - (Ten * 10);
//
//        fResult = Back + Ten * 0.1f + One * 0.01f;
//    }
//    else
//        fResult = num / 1000.f;
//
//    return fResult;
//}
//
//bool Compare(int a, int b)
//{
//    float ChangeA = ChangeNum(a);
//    float ChangeB = ChangeNum(b);
//
//    return ChangeA > ChangeB;
//}
//
//void MySort(vector<int> numbers)
//{
//    sort(numbers.begin(), numbers.end(), Compare);
//    bool b = false;
//}

bool cmp(const string& a, const string& b)
{
    int a_size = a.size();
    int b_size = b.size();

    return a < b;
}


bool solution(vector<string> phone_book) {
    bool answer = true;

    for (auto str : phone_book)
    {
        string::size_type t = str.size();
        int Count = 0;
        for (auto str : phone_book)
        {
            int Count = 0;
            for (auto Temp : phone_book)
            {
                


            }
        }
    }

    return answer;
}


int main()
{
    vector<string> Test = { "119", "97674223", "1195524421" };

    solution(Test);
    bool b = false;
}