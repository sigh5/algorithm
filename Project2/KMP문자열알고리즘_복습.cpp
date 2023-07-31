#include <iostream>
#include <string>
#include <vector>

using namespace std;

//// 실패테이블을 직접 만드는 함수
//vector<int> makeTable(string str)
//{ // 실패시 최대 길이만큼 점프를 해서 반복되는 연산을 줄인다.
//	int iPatternSize = str.size();
//	vector<int> table(iPatternSize, 0);
//
//	int j = 0;
//	// i 는 계속 증가시키고 j의 인덱스를 가진 table 이 
//	// 같지않다면 계속해서 감소시킨다.
//	for (int i = 1; i < iPatternSize; ++i)
//	{
//		while (j > 0 && str[i] != str[j]) 
//		{ // (j는 테이블 인덱스) 인덱스가 0보다 크고
//			// 같지 않을때까지 이전 테이블의 인덱스를 참고한다.
//			j = table[j-1];
//		}
//		if (str[i] == str[j])
//			table[i] = j++;		// 일치할 때 i,j 둘다 증가시킨다.
//	}
//	return table;
//}
//
//void KMP(string text, string pattern)
//{
//
//
//	int textSize = text.size();
//	int PatternSize = pattern.size();
//
//	vector<int> patternTable = makeTable(pattern);
//
//	int j = 0;
//
//	for (int i = 0; i < textSize; ++i)
//	{
//		while (j > 0 && text[i] != pattern[j])
//		{
//			j = patternTable[j - 1];
//		}
//		if (text[i] == pattern[j])
//		{
//			if (j == PatternSize - 1)
//			{
//				cout << i - PatternSize + 2 << "에서 찾았습니다" << endl;
//				j = patternTable[j]; // 계속해서 찾기
//			}
//			else
//			{
//				++j;
//			}
//		}
//	}
//
//
//}

//// 실패시 jump 할 테이블을 만든다.
//vector<int> Make_PatternTable(string pattern)
//{
//	int iPatternSize = pattern.size();
//	vector<int> table(iPatternSize, 0);
//
//	int j = 0;
//	for (int i = 1; i < iPatternSize; ++i)
//	{
//		while (j > 0 && pattern[i] != pattern[j])
//		{
//			j = table[j - 1]; //같지 않을때 그전 테이블인덱스를 참고한다.
//		}
//		if (pattern[i] == pattern[j])
//		{
//			table[i] = j++;  // i 값과 j값 둘다 증가시킨다.
//		}
//	}
//	return table;
//}
//
//void KMP(string text, string pattern)
//{
//	int itextSize = text.size();
//	int ipatternSize = pattern.size();
//
//	vector<int> JumpTable = Make_PatternTable(pattern);
//
//	int j = 0;
//
//	for (int i = 0; i < itextSize; ++i) // 비교할 텍스트가 i
//	{
//		while (j > 0 && text[i] != pattern[j]) // 같지 않을 때 이전 인덱스로 점프한다.
//		{
//			j = JumpTable[j-1];
//		}
//
//		if (text[i] == pattern[j])
//		{
//			if (j == ipatternSize - 1) // 문자열이 패턴의 길이와 전부 같다면?
//			{
//				cout << i - ipatternSize + 2 << "에서 찾았습니다" << endl;   //  i : Text의 지금까지 온 인덱스 pattenr의 전체길이를 뺀후 +2를 해서 
//																			//   겹친 인덱스중 시작 지점을 구한다.
//				j = JumpTable[j];		//연속해서 다음에 일치하는 지점을 찾는다.
//			}
//			else
//			{
//				++j;		// j값을 증가시켜 위치를 찾는다.
//			}
//		}
//	}
//}

vector<int> make_Table(const string pattern, int PatternSize)
{
	vector<int> Table(PatternSize, 0);
	int j = 0;

	for (int i = 1; i < PatternSize; ++i)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = Table[j - 1];
		}

		if (pattern[i] == pattern[j])
		{
			Table[i] = j++;
		}
	}

	return Table;
}


void KMP(const string text, const string pattern)
{
	int textSize = text.size();
	int patternSize = pattern.size();

	vector<int> PatternTable = make_Table(pattern,patternSize);

	int j = 0;
	for (int i = 0; i < textSize; ++i)
	{
		while (j > 0 && text[i] != pattern[j])
		{
			j = PatternTable[j - 1];
		}

		if (text[i] == pattern[j])
		{
			if (j == patternSize - 1)
			{
				cout << i - patternSize + 2 << "에서 찾았습니다" << endl;
				j = PatternTable[j];
			}
			else
				j++;
		}
	}

	

}


int main()
{
	string parent = "abaabaaba";
	string pattern = "aba";
	

	KMP(parent, pattern);

	return 0;
}
