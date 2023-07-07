#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> makeTable(string str)
{
	int patternSize = str.size();
	vector<int> table(patternSize, 0);

	int j = 0;

	for (int i = 1; i < patternSize; ++i)
	{
		while (j > 0 && str[i] != str[j])
		{
			j = table[j - 1];
		}
		if (str[i] == str[j])
		{
			table[i] = ++j;
		}
	}

	return table;
}
void KMP(string parent, string pattern)
{
	vector<int> table = makeTable(pattern);
	int patternSize = pattern.size();
	int parentSize = parent.size();

	int j = 0; 

	for (int i = 0; i < parentSize; ++i)
	{
		while (j > 0 && parent[i] != pattern[j])
		{
			j = table[j - 1];
		}
		if (parent[i] == pattern[j])
		{
			if (j == patternSize - 1)
			{
				cout << i - patternSize + 2 << "에서 찾았습니다." << " ";
				j = table[j];
			}
			else
				j++;
		}
	}

}


int main()
{
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	vector<int>table = makeTable(pattern);

	KMP(parent, pattern);

	return 0;
}
