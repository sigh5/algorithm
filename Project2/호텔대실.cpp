#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int solution(vector<vector<string>> book_time) {
    
	int answer = 1;
	
	vector<pair<int, int>> timeVec;
	
	int start_hour = 0, start_min = 0 , end_hour=0 , end_min=0;
	for (auto time : book_time)
	{
		start_hour =  stoi(time[0].substr(0, 2)) * 60;
		start_min = stoi(time[0].substr(3));
		end_hour = stoi(time[1].substr(0, 2)) * 60;
		end_min = stoi(time[1].substr(3)) + 10;

		timeVec.push_back({ start_hour + start_min, end_hour + end_min });
	}

	sort(timeVec.begin(), timeVec.end(), [](auto& a, auto& b)
	{
		return a.first < b.first;
	});

	vector<pair<int, int>> Filed;

	for (auto time : timeVec)
	{
		int start = time.first;
		vector<pair<int, int>> temp;

		for (auto room : Filed)
		{
			if (start < room.second )
			{
				temp.push_back(room);
			}
		}

		Filed = temp;
		Filed.push_back(time);
		answer = max(answer, int(Filed.size()));
	}
	

	return answer;
}


int main()
{
	vector<vector<string>> book_time{ {"15:00", "17:00"},{"16:40", "18:20"},{"14:20", "15:20"},{"14:10", "19:20"},{"18:20", "21:20"} };
	cout << solution(book_time);

	return 0;
}