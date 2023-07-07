#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int find_BoyerMoore(const string Text, const string pattern)
{
	int answer = -1;

	int n = Text.size();
	int m = pattern.size();

	unordered_map<char, int> last;

	for (int i = 0; i < n; ++i)
	{
		last[Text[i]] = -1;
	}

	for (int i = 0; i < m; ++i)
	{
		last[pattern[i]] = i;
	}

	int i = m - 1;  // index Text
	int j = m - 1;  // index Pattern

	while (i < n)
	{
		if (Text[i] == pattern[j])
		{
			if (j == 0)
			{
				return i;	// match ����
			}
			--i, --j;   // 0�̸� �� ��ġ�ȰŰ� 
						// 0�϶����� �ٸ�ġ�Ǵ��� Ȯ���Ѵ�.
			
		}
		else
		{
			i += m - min( 1 + last[Text[i]], j); // ���� Ŀ���� ������ �ǹǷ� �װ�Ƽ�긦 �� �������Ѵ�.
			j = m - 1;
		}
	}

	cout << "NonFound" << endl;
	return answer;
}

int main()
{
	string OriginText = "abaabaababbabababcabccaabcabcabcbcabcbacba";
	string Pattern = "abbab";

	cout << find_BoyerMoore(OriginText, Pattern);

	return 0;
}
