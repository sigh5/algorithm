#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T , typename Container = vector<T> , typename Predicate =less<T> >
class Priority_Queue
{
public:
	void push(const T& data)
	{
		_heap.push_back(data);

		// �ε��� = ������ -1 
		int now = static_cast<int>(_heap.size())-1;
		
		// ���ǿ� ������ ��Ʈ ������ �� ����.
		while (now > 0)
		{
			// ������ �θ��ε����� ����.
			int next = (now - 1) / 2;

			// �θ��ε����� ������ ������ �״�� �����ִ´�
			if (_predict(_heap[now] , _heap[next]))
				break;

			// �θ��� ���� ���ǿ� �¾Ƽ� �۰ų� ũ�� �����͸� ��ü�Ѵ�.
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
			// �ڽ� �ε��� ã��
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			int next = now;

			if (left >= _heap.size())
				break;

			if (_predict(_heap[next], _heap[left]))
				next = left;

			if (right < _heap.size() && _predict(_heap[next], _heap[right]))
				next = right;

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
	Predicate	_predict = {};


};





int main()
{
	Priority_Queue<int, vector<int>, greater<int>> pq;

	pq.push(100);
	pq.push(300);
	pq.push(200);
	pq.push(500);
	pq.push(400);

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}

