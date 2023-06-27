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
				return i;	// match 됐음
			}
			--i, --j;   // 0이면 다 매치된거고 
						// 0일때까지 다매치되는지 확인한다.
			
		}
		else
		{
			i += m - min( 1 + last[Text[i]], j); // 값이 커지면 음수가 되므로 네거티브를 할 수없이한다.
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
