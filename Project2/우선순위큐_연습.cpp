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

		// 인덱스 = 사이즈 -1 
		int now = static_cast<int>(_heap.size())-1;
		
		// 조건에 맞으면 루트 노드까지 쭉 간다.
		while (now > 0)
		{
			// 현재의 부모인덱스로 간다.
			int next = (now - 1) / 2;

			// 부모인덱스의 값보다 작으면 그대로 남아있는다
			if (_predict(_heap[now] , _heap[next]))
				break;

			// 부모의 값이 조건에 맞아서 작거나 크면 데이터를 교체한다.
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
			// 자식 인덱스 찾기
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

