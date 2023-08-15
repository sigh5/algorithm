

#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<int> makeTable(string pattern)
{
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);

	int j = 0;

	for (int i = 1; i < patternSize; ++i)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j])
			table[i] = ++j;
	}


}