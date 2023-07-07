#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> make_table(const string patten)
{
	int patternSize = patten.size();
	vector<int> table(patternSize, 0);

	int j = 0;

	for (int i = 1; i < patternSize; ++i) // i�� 1���� ����
	{
		while (j > 0 && patten[i] != patten[j])
		{
			j = table[j - 1]; // patten[i] != patten[j] �� �����ʴ�? 
							  // j���� �������� ����������
		}
		if (patten[i] == patten[j])
		{
			table[i] = ++j;
		}
	}
	return table;
}


vector<int> Find_KMP(const string text, const string pattern)
{
	vector<int> answer;

	vector<int> table = make_table(pattern);
	int textSize = text.size();
	int pattenSize = pattern.size();

	int j = 0;

	for (int i = 0; i < textSize; ++i)
	{
		while (j > 0 && text[i] != pattern[j])
		{
			j = table[j - 1];
		}
		if (text[i] == pattern[j])
		{
			if (j == pattenSize - 1) {
				answer.push_back(i - pattenSize + 2);
				j = table[j];

			}
			else
				++j;
		}



	}

	return answer;
}

vector<int> Find_BoyerMoore(const string text, const string pattern)
{
	vector<int> answer;
	int n = text.size();
	int m = pattern.size();

	unordered_map<char, int> last;

	for (int i = 0; i < n; ++i)
	{
		last[text[i]] = -1;
	}

	for (int i = 0; i < m; ++i)
	{
		last[pattern[i]] = i;
		// �ߺ��Ǹ� ���� �������� �ִ� ���� �����.
	}

	int i = m - 1;  // text Index  // �ϴ� ������ ������ �ε������κп��� �����ϰڴ� 
	int j = m - 1;  // patten Index 

					//  A B C D E F
					//  A D E   ->E�κк��� ��ġ�ϰڴ�.
	while (i < n)
	{
		if (text[i] == pattern[j]) // �Ǵ� �ε��� ã��
		{
			if (j == 0)
			{
				answer.push_back(i);
				j = m - 1;
				i += m + 1;
			}
			--i, --j;  // ������ �ε����� ���� ������ Ȯ�� 
		}
		else  //������ �ε����� ã�´�.
		{
			i += m - min(j, 1 + last[text[i]]); // �׸��� i�� ����̵��Ѵ�.
			j = m - 1;
		}
	}

	return answer;
}

int main()
{
    const string h = "abaabaababbabababcabccaabcabcabcbcabcbacba";
    const string pattern = "abbab";
    const int p_size = pattern.size();

    const vector<int> bc_table = make_to_bad_character_tb(pattern);     // bad_Char Table
    const vector<int> gs_table = make_to_gs_tb(pattern);                // Good_Char Table

    cout << search(bc_table, gs_table, h, pattern) << endl;

    return 0;
}

