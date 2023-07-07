#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> make_table(const string pattern,int patternSize)
{
	vector<int> table(patternSize, 0);

	int j = 0;
	for (int i = 1; i < patternSize; ++i)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = table[j - 1];
		}

		if (pattern[i] == pattern[j])
		{
			table[i] = ++j;
		}
	}

	return table;
}


vector<int> Find_KMP(const string text, const string pattern)
{
	vector<int> answer;
	int text_size = text.size();
	int pattern_size = pattern.size();

	vector<int> table = make_table(pattern,pattern_size);

	int j = 0;
	for (int i = 0; i < text_size; ++i)
	{
		while (j > 0 && text[i] != pattern[j]) // 실패했다.
		{
			j = table[j - 1]; // j 를 실패한 인덱스 전으로 되돌린다.
		}
		
		if (text[i] == pattern[j])
		{
			if (j == pattern_size - 1)
			{
				answer.push_back(i - pattern_size + 2);
				j = table[j];
			}
			else
				++j;
		}
		

	}

	return answer;
}


int main()
{
	string pattern = "abacaaba";

	vector<int> table =    make_table(pattern, pattern.size());

	bool b = false;
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);





	string text;
	string pattern;


	getline(cin, text);
	getline(cin, pattern);

	vector<int> Result = Find_KMP(text, pattern);

	cout << Result.size() <<endl;
	
	for (auto StartIndex : Result)
	{
		cout << StartIndex+1 << " ";
	}

	return 0;
	*/
}


