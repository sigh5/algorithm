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
		for (int j = 0; j < 9 - i; ++j)   // 9-i 하는 이유 뒤에서부터 하나씩 제거하며 버블정렬을 하기 때문에 시간복잡도 O n^2
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

void Insert_Sort()		// 앞에있는 원소들이 정렬되어있다고 가정한다. 시간 복잡도 On^2
{
	int j = 0, temp=0;
	for (int i = 0; i < 10-1; ++i)		// 제일 앞에 있는 원소는 계산 x 
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
	// 재귀함수를 쓸거니까 리턴 값 잡아주고
	if (iStart >= iEnd)
		return;

	int Key = iStart, 
	i = iStart + 1, 
	j = iEnd, temp = 0;

	// iStart ++ 큰값 찾고  iEnd-- 에서 작은값을 찾는다.


	while (i <= j) //엇갈릴 때 까지 찾는다.
	{
		while (i <= iEnd && arr[i] <= arr[Key]) // 큰 값을 찾을 때 까지 ++
		{
			++i;
		}
		while (j > iStart && arr[j] >= arr[Key])   //작은값을 찾을때 까지 --
		{
			--j;
		}


		if (i > j)  // 엇갈렷다. 엇갈린 상태와 키 값을 바꿔준다.
		{
			temp = arr[j];
			arr[j] = arr[Key];
			arr[Key] = temp;
		}
		else       // 엇갈리지 않고 왔다.  i와 j  값을 바꿔준다.
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	// j 아래 인덱스 까지는 arr[j] 보다 작은수이다.

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
	// 최대 힙 만들기
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

	// 크기를 줄여가며 반복적으로 힙 구성
	for (int i = 10; i >= 0; --i)
	{
		int temp = heap[0];	    // 0번째는 가장 큰값임 가장 큰값을 맨뒤로 바꿔 오름차순으로 계속해서 바꿔줌
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do
		{
			// 자식 중에 더 큰 값 찾기
			if (c < i - 1 && heap[c] < heap[c + 1])
			{
				++c;
			}
			// 루트보다 자식이 크다면 교환
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
	// 최대 힙 만들기 
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


	// 크기를 줄여가며 반복

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
			//자식들과의 비교
			if (c < i - 1 && heap[c] < heap[c + 1])		// c < i - 1  범위를 벗어나지 않도록 만듦 자식들과의 비교를위해
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
