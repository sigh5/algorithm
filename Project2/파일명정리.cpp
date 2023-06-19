#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct FileData
{
    string Head = "";
    int Number = 0;
    int Index = 0;
};

bool Cmp(FileData& a, FileData& b)
{
    if (a.Head == b.Head)
    {
        if (a.Number == b.Number)
        {
            return a.Index < b.Index;
        }
        else
            return a.Number < b.Number;

    }
    else
    {
        return a.Head < b.Head;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<FileData> SortVec;

    int Size = files.size();

    for (int i = 0; i < Size; ++i)
    {
        FileData file_data;
        bool bNumber = false;
        bool bFinishNumber = false;
        string Number = "";
        for (int j = 0; j < files[i].size(); ++j)
        {
            if (!bFinishNumber && '0' <= files[i][j] && '9' >= files[i][j])
            {
                Number += files[i][j];
                bNumber = true;
            }
            else if (!bNumber)
            {
                file_data.Head += tolower(files[i][j]);
            }
            else
            {
                bFinishNumber = true;
            }
        }
        file_data.Index = i;
        file_data.Number = stoi(Number);
        SortVec.push_back(file_data);
    }

    sort(SortVec.begin(), SortVec.end(), Cmp);

    for (int i = 0; i < Size; ++i)
    {
        string str = files[SortVec[i].Index];
        answer.push_back(str);
    }

    return answer;
}

int main()
{
    vector<string> files{ "img12.png", "img10.png", "img02.png", 
        "img1.png", "IMG01.GIF", "img2.JPG" };
    
    
    solution(files);

    return 0;
}