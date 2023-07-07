#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


int WidthCheck(vector<string> board, char Data)
{
	int answer = 0;

	for (int i = 0; i < 3; ++i)
	{

		if (board[0][i] != '.' &&
			board[0][i] == Data &&
			board[0][i] == board[1][i] && board[0][i] == board[2][i])
		{
			++answer;
		}

	}

	return answer;
}

int HeightCheck(vector<string> board, char Data)
{
	int answer = 0;

	for (int i = 0; i < 3; ++i)
	{
		if (board[i][0] != '.' &&
			board[i][0] == Data &&
			board[i][0] == board[i][1] && board[i][0] == board[i][2])
			++answer;
	}

	return answer;
}


int DiaCheck(vector<string> board, char Data)
{
	int answer = 0;

	if (board[0][0] != '.' &&
		board[0][0] == Data &&
		board[0][0] == board[1][1] && board[0][0] == board[2][2])
		++answer;

	if (board[0][2] != '.' &&
		board[0][2] == Data &&
		board[0][2] == board[1][1] && board[0][2] && board[2][0])
		++answer;

	return answer;
}

int solution(vector<string> board) {
	int answer = 1;

	int FirstCnt = 0;
	int SecondCnt = 0;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (board[i][j] == 'O')
				++FirstCnt;
			if (board[i][j] == 'X')
				++SecondCnt;
		}
	}
	if (SecondCnt > FirstCnt || FirstCnt - SecondCnt > 1)
		return 0;
	
	int Win0 = 0;
	int Win1 = 0;
	Win0 = WidthCheck(board, 'O') + HeightCheck(board, 'O') + DiaCheck(board, 'O');
	Win1 = WidthCheck(board, 'X') + HeightCheck(board, 'X') + DiaCheck(board, 'X');

	if (FirstCnt - SecondCnt == 1)
	{
		if (Win0 > Win1)
			answer = 1;
		else if (Win0 + Win1 == 0)
			answer = 1;
		else
			answer = 0;
	}
	else if (FirstCnt - SecondCnt == 0)
	{
		if (Win1 > Win0)
			answer = 1;
		else if (Win0 + Win1 == 0)
			answer = 1;
		else
			answer = 0;
	}



	
	return answer;
}

int main()
{
	vector<string> board{ "OOO", "XX.", "X.." };

	cout << solution(board);




	return 0;
}


//if (FirstCnt - SecondCnt == 1) // 선공이 무조건 이기는 경우
//{
//    if (Win0 > Win1) // 무조건 하나 많다.
//        answer = 1;
//    else if (Win0 + Win1 == 0)
//        answer = 1;
//    else
//        answer = 0;
//}
//else if (FirstCnt - SecondCnt == 0) //X가 이긴경우만 참
//{
//    if (Win0 < Win1)        // 후공이 이겼을 때 
//        answer = 1;
//    else if (FirstCnt + SecondCnt == 0) //  아무것도 놓지 않았을때
//        answer = 1;
//    else if (Win0 + Win1 == 0) //  놓았지만  아무도 이기지 않았을 때
//        answer = 1;
//
//    else
//        answer = 0;
//}
//else  // FirstCnt < SecondCnt 이런 경우는 없다.
//{
//    answer = 0;
//}


//if (Win0 > Win1)
//{
//	if (FirstCnt - SecondCnt == 1)
//		answer = 1;
//	else
//		answer = 0;
//}
//else if (Win0 + Win1 == 0)
//{
//	if (FirstCnt == SecondCnt)
//		answer = 1;
//	else if (FirstCnt > SecondCnt)
//		answer = 1;
//	else
//		answer = 0;
//}
//else if (Win0 < Win1)
//{
//	if (FirstCnt == SecondCnt)
//		answer = 1;
//	else
//		answer = 0;
//}
//else
//answer = 0;
