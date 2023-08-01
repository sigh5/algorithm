#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;





vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;


    vector<vector<int>> Node(n+1,vector<int> (0));

    int RoadSize = roads.size();

    for (int i = 0; i < RoadSize; ++i)
    {
        Node[roads[i][0]].push_back(roads[i][1]);
        Node[roads[i][1]].push_back(roads[i][0]);
    }

    
   vector<int> costFromDestination(n + 1, -1);
   costFromDestination[destination] = 0;
    queue<pair<int, int>> q;

    q.push({ destination,0 });

    while (!q.empty())
    {
        int CurPos = q.front().first;
        int CurCost = q.front().second;
        q.pop();


        int NodeSize = Node[CurPos].size();

        for (int i = 0; i < NodeSize; ++i)
        {
            int NextPos = Node[CurPos][i];


            if (costFromDestination[NextPos] == -1 || costFromDestination[NextPos] > CurCost + 1)
            {
                q.push({ NextPos,CurCost + 1 });
                costFromDestination[NextPos] = CurCost + 1;
            }
        }

    }

    int SourcesSize = sources.size();

    for (int i = 0; i < SourcesSize; ++i)
    {
        answer.push_back(costFromDestination[sources[i]]);
    }




    return answer;
}

int main()
{

    vector<vector<int>> roads{ {1, 2 },{1,4},{2,4}, { 2, 5 },{4,5} };
    vector<int> sources{ 1,3,5 };


    solution(5, roads, sources,5);


	return 0;
}