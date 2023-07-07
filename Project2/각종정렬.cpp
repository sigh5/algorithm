#include <iostream>
#include <array>
#include <algorithm>

using namespace std;


int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };


void Bubble_Sort()
{
	int temp = 0;

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 9 - i; ++j)   // 9-i �ϴ� ���� �ڿ������� �ϳ��� �����ϸ� ���������� �ϱ� ������ �ð����⵵ O n^2
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void Insert_Sort()		// �տ��ִ� ���ҵ��� ���ĵǾ��ִٰ� �����Ѵ�. �ð� ���⵵ On^2
{
	int j = 0, temp=0;
	for (int i = 0; i < 10-1; ++i)		// ���� �տ� �ִ� ���Ҵ� ��� x 
	{
		j = i;

		while (j >= 0 && arr[j] > arr[j + 1])
		{
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			--j;
		}
	}
}

void My_Quick_Sort(int iStart, int iEnd)
{
	// ����Լ��� ���Ŵϱ� ���� �� ����ְ�
	if (iStart >= iEnd)
		return;

	int Key = iStart, 
	i = iStart + 1, 
	j = iEnd, temp = 0;

	// iStart ++ ū�� ã��  iEnd-- ���� �������� ã�´�.


	while (i <= j) //������ �� ���� ã�´�.
	{
		while (i <= iEnd && arr[i] <= arr[Key]) // ū ���� ã�� �� ���� ++
		{
			++i;
		}
		while (j > iStart && arr[j] >= arr[Key])   //�������� ã���� ���� --
		{
			--j;
		}


		if (i > j)  // �����Ǵ�. ������ ���¿� Ű ���� �ٲ��ش�.
		{
			temp = arr[j];
			arr[j] = arr[Key];
			arr[Key] = temp;
		}
		else       // �������� �ʰ� �Դ�.  i�� j  ���� �ٲ��ش�.
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	// j �Ʒ� �ε��� ������ arr[j] ���� �������̴�.

	My_Quick_Sort(iStart, j-1);
	My_Quick_Sort(j + 1, iEnd);

}

int Sorted[10]{};
void MyMerge(int iStart, int iMiddle, int iEnd)
{
	int i = iStart;
	int j = iMiddle + 1;
	int k = iStart;

	while (i <= iMiddle && j <= iEnd)
	{
		if (arr[i] <= arr[j])
		{
			Sorted[k] = arr[i];
			i++;
		}
		else
		{
			Sorted[k] = arr[j];
			j++;
		}
		++k;
	}

	if (i > iMiddle)
	{
		for (int t = j; t <= iEnd; ++t)
		{
			Sorted[k] = arr[t];
			++k;
		}
	}
	else
	{
		for (int t = i; t <= iMiddle; ++t)
		{
			Sorted[k] = arr[t];
			++k;
		}
	}

	for (int t = iStart; t <= iEnd; ++t)
	{
		arr[t] = Sorted[t];
	}
}

void MyMergeSort(int m, int n)
{
	if (m < n)
	{
		int middle = (m + n) / 2;
		MyMergeSort( m, middle);
		MyMergeSort( middle + 1, n);
		MyMerge( m, middle, n);
	}
}


int heap[]{ 1,10,5,8,7,6,4,3,2,9 };

const int iMaxHeapNumber = 10;
void MyHeapSort()
{
	// �ִ� �� �����
	for (int i = 1; i < iMaxHeapNumber; ++i)
	{
		int c = i;

		do
		{
			int root =  (c-1)/2 + 1;

			if (heap[root] < heap[c])
			{
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}

	// ũ�⸦ �ٿ����� �ݺ������� �� ����
	for (int i = 10; i >= 0; --i)
	{
		int temp = heap[0];	    // 0��°�� ���� ū���� ���� ū���� �ǵڷ� �ٲ� ������������ ����ؼ� �ٲ���
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do
		{
			// �ڽ� �߿� �� ū �� ã��
			if (c < i - 1 && heap[c] < heap[c + 1])
			{
				++c;
			}
			// ��Ʈ���� �ڽ��� ũ�ٸ� ��ȯ
			if (c<i && heap[c] > heap[root])
			{
				int temp = heap[c];
				heap[c] = heap[root];
				heap[root] = temp;
			}
			root = c;
		} while (c < i);
	}


}


void HeapSort()
{
	// �ִ� �� ����� 
	for (int i = 1; i < 10; ++i)
	{
		int c = i;

		do
		{
			int root = (c - 1) / 2;

			if (heap[root] < heap[c])
			{
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}


	// ũ�⸦ �ٿ����� �ݺ�

	for (int i = 10 - 1; i >= 0; --i)
	{
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;

		do
		{
			c = 2 * root + 1;
			//�ڽĵ���� ��
			if (c < i - 1 && heap[c] < heap[c + 1])		// c < i - 1  ������ ����� �ʵ��� ���� �ڽĵ���� �񱳸�����
			{
				++c;
			}

			if (c < i && heap[c] > heap[root])
			{
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;

		} while (c < i);

	}

}


void OutPut()
{
	for (int i = 0; i < 10; ++i)
	{
		cout << heap[i] << " ";
	}
}


int main()
{
	
	HeapSort();
	OutPut();

}
