#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <array>
using namespace std;


//vector<int> solution(vector<int> progresses, vector<int> speeds) {
//
//    vector<int> answer;
//    int iCompleteIndex = 0;
//    while (iCompleteIndex < (int)progresses.size() )
//    {
//        int iCount = 0;
//        int iProgressSize = progresses.size();
//
//        for (int i = 0; i < iProgressSize; ++i)
//        {
//            progresses[i] += speeds[i];
//        }
//
//        for (int i = iCompleteIndex; i < iProgressSize; ++i)
//        {
//            if (progresses[i] >= 100)
//            {
//                ++iCompleteIndex;
//                ++iCount;
//            }
//            else
//                break;
//        }
//
//
//        if (iCount >= 1)
//        {
//            answer.push_back(iCount);
//
//
//        }
//    }
//    return answer;
//}

int solution(vector<vector<string>> clothes) {
	int answer = 0;

	unordered_map<string, int> HashMap;
	int InputClothSize = clothes.size();

	for (int i = 0; i < InputClothSize; ++i)
	{
		HashMap[clothes[i][1]]++;
	}

	int iCount = HashMap[clothes[0][1]];
	int iIndex = 0;
	for (auto Hash : HashMap)
	{
		answer += Hash.second;

		if (iIndex != 0)
		{
			iCount *= Hash.second;
		}
		++iIndex;
	}

	answer += iCount;

	return answer;
}

//int solution(vector<int> priorities, int location) {
//
//    int answer = 0;
//    queue<pair<int, int>> q; // Priority, Index
//    priority_queue<int> pq;
//    for (int i = 0; i < priorities.size(); ++i)
//    {
//        q.push({ priorities[i],i });
//        pq.push(priorities[i]);
//    }
//
//
//    int iReturnNum = 1;
//    while (!q.empty())
//    {
//        int qSize = q.size();
//        int iMax = -1;
//
//
//        int iCurData = q.front().first;
//
//        if (iCurData == pq.top())
//        {
//            if (location == q.front().second)
//            {
//                answer = iReturnNum;
//                break;
//            }
//            else
//            {
//                pq.pop();
//                iReturnNum++;
//                q.pop();
//            }
//        }
//        else
//        {
//            int icurData = q.front().first;
//            int iLocation = q.front().second;
//            q.pop();
//            q.push({ icurData,iLocation });
//        }
//
//    }
//
//    return answer;
//}
int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int answer = 0;

	vector<pair<int, int>> vec;

	for (auto Weight : truck_weights)
		vec.push_back({ Weight,bridge_length });

	int iIndex = 0;
	int iCount = 0;

	if(vec.size() == 1)

	while (iIndex < vec.size())
	{
		int Sum = 0;

		for (int i = iIndex; i < vec.size(); ++i)
		{
			Sum += vec[i].first;

			if (Sum <= weight)
			{
				iIndex = i + 1;
				iCount++;
			}
			else
			{
				iIndex = i;
				break;
			}
		}

		++iCount;
	}


	bridge_length += iCount;
	answer = bridge_length;
	return answer;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int answersSize = answers.size();

    vector<int> One, Two, Three;

    int idxOne = 1;
    int idxTwo = 1;
    for (int i = 1; i <= answersSize; ++i)
    {
        // 1번 수포자
        {
            One.push_back(idxOne);
            idxOne++;
            if (idxOne == 6)
                idxOne = 1;
        }
        // 2번 수포자
        {
            if (i % 2 == 1)
                Two.push_back(2);
            else
            {
                Two.push_back(idxTwo);

                if (idxTwo >= 5)
                    idxTwo = 1;
                else
                    ++idxTwo;

                if (idxTwo == 2)
                    ++idxTwo;

            }
        }

        // 3번 수포자
        {
            // 3 1 2 4 5 
			int iThreeIndex = i % 10;
			array<int, 11>  ThreeAnswer{ 5,3,3,1,1,2,2,4,4,5 };

			Three.push_back(ThreeAnswer[iThreeIndex]);

        }

    }

	array<int, 3> arr{0};

    for (int i = 0; i < answersSize; ++i)
    {
        if (answers[i] == One[i])
            arr[0]++;

        if (answers[i] == Two[i])
            arr[1]++;

        if (answers[i] == Three[i])
            arr[2]++;
    }


	if (arr[0] != 0 && arr[0] >= arr[1] && arr[0] >= arr[2])
	{
		answer.push_back(1);

		if (arr[1] != 0 && arr[1] >= arr[2])
		{
			answer.push_back(2);

			if (arr[2] != 0)
				answer.push_back(3);
		}
		else if(arr[2] != 0)
		{
			answer.push_back(3);

			if (arr[1] != 0)
				answer.push_back(2);
		}
	}
	else if (arr[1] != 0 && arr[1] > arr[0] && arr[1] >= arr[2])
	{
		answer.push_back(2);

		if (arr[0] != 0 && arr[0] >= arr[2])
		{
			answer.push_back(1);

			if (arr[2] != 0)
				answer.push_back(3);
		}
		else if (arr[2] != 0)
		{
			answer.push_back(3);

			if (arr[0] != 0)
				answer.push_back(1);
		}
	}
	else if (arr[2] != 0 && arr[2] > arr[0] && arr[2] > arr[1])
	{
		answer.push_back(3);

		if (arr[0] != 0 && arr[0] >= arr[1])
		{
			answer.push_back(1);

			if (arr[1] != 0)
				answer.push_back(2);
		}
		else if (arr[1] != 0)
		{
			answer.push_back(2);

			if (arr[0] != 0)
				answer.push_back(1);
		}
	}


	
    return answer;
}


int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int,vector<int>,greater<int>> pq;

	for (auto Food : scoville)
	{
		pq.push(Food);
	}


	while (true)
	{
		int Curfood = pq.top();

		if (Curfood >= K)
			break;
		pq.pop();

		int NextFood = pq.top();
		int NewFood = Curfood + (2 * NextFood);
		pq.pop();

		pq.push(NewFood);

		++answer;
	}

	return answer;
}

int main()
{
	//vector<int> progress{ 93, 30, 55 };
	//vector<int> speeds{ 1, 30, 5 };

	//solution(progress, speeds);

	//priority_queue<pair<int, int>> pq;  // priority, location
 /*   queue<pair<int, int>> pq;
	pq.t

	vector<int> priorities;
	int iIndex = 0;
	for (auto Data : priorities)
	{
		pq.push({ Data,iIndex });
		++iIndex;
	}*/

	vector<int> vec{ 1, 2, 3, 9, 10, 12 };


   solution(vec,7);



}