#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct Data
{
    int Dia = 0;
    int iron = 0;
    int Stone = 0;
};

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<Data> SumEnergy; // 5단위로 에너지 저장
    int Cnt = 0;
    Data data;
    for (auto mineral : minerals)
    {
        if (Cnt == 5)
        {
            SumEnergy.push_back(data);
            data.Dia = 0, data.iron = 0, data.Stone = 0;
            Cnt = 0;
        }
        if (mineral == "diamond")
        {
            data.Dia++;
        }
        else if (mineral == "iron")
        {
            data.iron++;
        }
        else
        {
            data.Stone++;
        }
        ++Cnt;
    }
    if (Cnt > 0)
    {
        SumEnergy.push_back(data);
    }
    
	sort(SumEnergy.begin(), SumEnergy.end(), [](auto& a, auto& b)
		{
			if (a.Dia == b.Dia)
			{
				if (a.iron == b.iron)
				{
					return a.Stone > b.Stone;
				}
				else
					return a.iron > b.iron;
			}
			else
				return a.Dia > b.Dia;
		});
    int CurMineCnt = 0;
    for (int i = 0; i < 3; ++i)
     {
          while (picks[i] > 0 && CurMineCnt < SumEnergy.size())
          {
              if (i == 0)
              {
                  answer += SumEnergy[CurMineCnt].Dia +
                      SumEnergy[CurMineCnt].iron + SumEnergy[CurMineCnt].Stone;
              }
              else if (i == 1)
              {
                  answer += SumEnergy[CurMineCnt].Dia * 5 +
                      SumEnergy[CurMineCnt].iron + SumEnergy[CurMineCnt].Stone;
              }
              else if (i == 2)
              {
                  answer += SumEnergy[CurMineCnt].Dia * 25 +
                      SumEnergy[CurMineCnt].iron * 5 + SumEnergy[CurMineCnt].Stone;
              }

              --picks[i];
              ++CurMineCnt;
          }

          if (CurMineCnt == SumEnergy.size())
              break;

     }


  
    return answer;
}

int main()
{
    vector<int> picks{ 1,1,0 };
    vector<string> minerals {"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone","iron", "iron", "diamond","diamond"};

    solution(picks,minerals);

    return 0;
}



