#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);

    while (s!="1")
    {
        string NewStr = "";
        int strSize = s.size();
        bool IsZeroChange = false, IsBitSet = false;
        for (int i = 0; i < strSize; ++i)
        {
            if (s[i] != '0')
            {
                NewStr += s[i];
            }
            else
            {
                answer[1]++;
            }
     
        }
    
        int NewStrSize = NewStr.size();
		bitset<32> Temp(NewStrSize);
		int FirstOneIndex = 0;
		for (int i = 0; i < 32; ++i)
		{
			if (Temp.test(i))
			{
				FirstOneIndex = i;
				IsBitSet = true;
			}
		}
       
		if (IsBitSet && s != "1")
		{
            s = "";
            for (int i = FirstOneIndex; i >= 0; --i)
            {
                s += (Temp[i] + '0');
            }
		}
        
        answer[0]++;
    }


    return answer;
}

int main()
{
    solution("110010101001");

    return 0;
}