#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <functional>
using namespace std;

template <typename T, typename Container = vector<T>,typename Predicate =less<T>>
class Priority_Queue
{
public:
	void	Push(const T& data)
	{
		// �켱 �� �������� �����ش�.
		_heap.push_back(data);

		// ������� ����
		int now = static_cast<int>(_heap.size()) - 1;

		// ��Ʈ ������
		while (now > 0)
		{
			// �θ� ����� �����Ϳ� ���ؼ� �������� �й�
			int next = (now - 1) / 2;
		/*	if (_heap[now] < _heap[next])
				break;*/

			if (_predicate(_heap[now], _heap[next]))
				break;


			// ������ ��ü
			::swap(_heap[now], _heap[next]);
			now = next;
		}

	}

	void pop()
	{
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			// ������ ������ ���
			if (left >= _heap.size())
				break;

			int next = now;

			// ���ʰ� ��
	/*		if (_heap[next] < _heap[left])
				next = left;*/
			if (_predicate(_heap[next], _heap[left]))
				next = left;


			// ��, �� ���ڸ� �����ʰ� ��
			//if (right < _heap.size() && _heap[next] < _heap[right])
			if (right < _heap.size() && _predicate(_heap[next], _heap[right]))
				next = right;

			// ���� / ������ �Ѵ� ���� ������ ������ ����
			if (next == now)
				break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	T& top()
	{
		return _heap[0];
	}

	bool empty()
	{
		return _heap.empty();
	}
	
private:
	Container	_heap = {};
	Predicate	_predicate={};


};



int main()
{
	Priority_Queue<int,vector<int>,greater<int>> pq;

	pq.Push(100);
	pq.Push(300);
	pq.Push(200);
	pq.Push(500);
	pq.Push(400);

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
	//Priority_Queue
}