#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
struct Data
{
	string Name;
	int CurTime;
	int UseTime;
};


vector<string> solution(vector<vector<string>> plans) {
	vector<string> answer;

	vector<Data> MyPlan;
	stack<Data> RestPlan;
	Data data;

	for (auto plan : plans)
	{
		data.Name = plan[0];
		string strHour;
		string strMin;
		for (int i = 0; i < plan[1].size(); ++i)
		{
			if (i < 2)
			{
				strHour += plan[1][i];
			}
			else if (i == 2)
				continue;
			else
				strMin += plan[1][i];

		}
		data.CurTime = stoi(strHour) * 60 + stoi(strMin);
		data.UseTime = stoi(plan[2]);
		MyPlan.push_back(data);
	}

	sort(MyPlan.begin(), MyPlan.end(), [](auto& a, auto& b)
		{
			return a.CurTime < b.CurTime;
		});

	int CurTime = 0;
	int StartIndex = 0;
	while (true)
	{
		int RestTime = MyPlan[StartIndex + 1].CurTime - (MyPlan[StartIndex].CurTime + MyPlan[StartIndex].UseTime); // 현재 남은시간

		if (RestTime >= 0) // 현재 시간이 다음 인덱스 시간 전일 경우
		{
			answer.push_back(MyPlan[StartIndex].Name);
			++StartIndex;

			if (!RestPlan.empty() && RestTime > 0)
			{
				while (!RestPlan.empty() && RestTime > 0)
				{
					int Origin = RestTime;
					RestTime -= RestPlan.top().UseTime;

					if (RestTime >= 0)
					{
						answer.push_back(RestPlan.top().Name);
						RestPlan.pop();
					}
					else
					{
						RestPlan.top().UseTime -= Origin;
						break;
					}
				}
			}
		}
		else
		{
			MyPlan[StartIndex].UseTime -= (MyPlan[StartIndex + 1].CurTime - MyPlan[StartIndex].CurTime);
			RestPlan.push(MyPlan[StartIndex]);
			++StartIndex;
		}




		if (StartIndex == plans.size() - 1)
		{
			answer.push_back(MyPlan[StartIndex].Name);
			break;
		}
	}

	while (!RestPlan.empty())
	{
		string CurName = RestPlan.top().Name;
		RestPlan.pop();
		answer.push_back(CurName);
	}


	return answer;
}


int main()
{
	vector<vector<string>> plans = { {"science", "12:40", "50"},{"music", "12:20", "40" },
		{"history", "14:00", "30" }, { "computer", "12:30", "100" } };

	solution(plans);

	return 0;
}