#include <iostream>
#include <string>
#include <vector>

using namespace std;

//// �������̺��� ���� ����� �Լ�
//vector<int> makeTable(string str)
//{ // ���н� �ִ� ���̸�ŭ ������ �ؼ� �ݺ��Ǵ� ������ ���δ�.
//	int iPatternSize = str.size();
//	vector<int> table(iPatternSize, 0);
//
//	int j = 0;
//	// i �� ��� ������Ű�� j�� �ε����� ���� table �� 
//	// �����ʴٸ� ����ؼ� ���ҽ�Ų��.
//	for (int i = 1; i < iPatternSize; ++i)
//	{
//		while (j > 0 && str[i] != str[j]) 
//		{ // (j�� ���̺� �ε���) �ε����� 0���� ũ��
//			// ���� ���������� ���� ���̺��� �ε����� �����Ѵ�.
//			j = table[j-1];
//		}
//		if (str[i] == str[j])
//			table[i] = j++;		// ��ġ�� �� i,j �Ѵ� ������Ų��.
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
//				cout << i - PatternSize + 2 << "���� ã�ҽ��ϴ�" << endl;
//				j = patternTable[j]; // ����ؼ� ã��
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

//// ���н� jump �� ���̺��� �����.
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
//			j = table[j - 1]; //���� ������ ���� ���̺��ε����� �����Ѵ�.
//		}
//		if (pattern[i] == pattern[j])
//		{
//			table[i] = j++;  // i ���� j�� �Ѵ� ������Ų��.
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
//	for (int i = 0; i < itextSize; ++i) // ���� �ؽ�Ʈ�� i
//	{
//		while (j > 0 && text[i] != pattern[j]) // ���� ���� �� ���� �ε����� �����Ѵ�.
//		{
//			j = JumpTable[j-1];
//		}
//
//		if (text[i] == pattern[j])
//		{
//			if (j == ipatternSize - 1) // ���ڿ��� ������ ���̿� ���� ���ٸ�?
//			{
//				cout << i - ipatternSize + 2 << "���� ã�ҽ��ϴ�" << endl;   //  i : Text�� ���ݱ��� �� �ε��� pattenr�� ��ü���̸� ���� +2�� �ؼ� 
//																			//   ��ģ �ε����� ���� ������ ���Ѵ�.
//				j = JumpTable[j];		//�����ؼ� ������ ��ġ�ϴ� ������ ã�´�.
//			}
//			else
//			{
//				++j;		// j���� �������� ��ġ�� ã�´�.
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
				cout << i - patternSize + 2 << "���� ã�ҽ��ϴ�" << endl;
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
