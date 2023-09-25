#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;




vector<int> solution(vector<vector<int>> orders)
{
	vector<int> answer;

	int orderSize = orders.size();
	int SelectNum = 0;

	if (orderSize % 2 == 0)
		SelectNum = orderSize / 2;
	else
		SelectNum = (orderSize + 1) / 2;
	
	vector<int> FireNum(orderSize, 0);
	
	
	int idx = 0;

	while (true)
	{
		vector<pair<int, int>> SelectMap;

		for (int i = 0; i < orderSize; ++i)
		{
			if(FireNum[i] != -1)
				SelectMap.push_back({ i,0 });
			else
				SelectMap.push_back({ i,-111 });
		}

		for (int i = 0; i < orderSize; ++i)
		{
			for (int j = 0; j < orderSize; ++j)
			{
				if (FireNum[orders[i][j]] == -1)
					continue;

				SelectMap[orders[i][j]].second += 1;
			}

		}

		sort(SelectMap.begin(), SelectMap.end(), [](auto a, auto b)
			{
				if (a.second == b.second)
				{
					return a.first < b.first;
				}
				else
					return a.second < b.second;
			});
		
		FireNum[SelectMap[idx++].first] = -1;
		
		if (SelectMap[orderSize - 1].second == SelectNum)
		{
			answer.push_back(idx);
			answer.push_back(SelectMap[orderSize - 1].first);
			break;
		}


		


		


		SelectMap.clear();

	}


		

	return answer;
}

int main()
{
	
	vector<vector<int>> orders{ {2,3,4,0,1},{1,4,3,2,0} ,{4,1,0,2,3}, {3,2,1,4,0},{0,3,2,1,4} };

	

	solution(orders);

	return 0;
}