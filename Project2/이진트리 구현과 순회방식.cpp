#include <iostream>
#include <algorithm>

using namespace std;

const int number = 15;

// �ϳ��� ��� ������ �����Ѵ�.

typedef struct node
{
	int data =0;
	node* leftChild = nullptr;
	node* rightChild = nullptr;

}node;




// ������ȸ
void preorder(node* ptr)
{
	if (ptr)
	{
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// ������ȸ
void inorder(node* ptr)
{
	if (ptr)
	{
		inorder(ptr->leftChild);
		cout << ptr->data<<' ';
		inorder(ptr->rightChild);
	}
}

void postorder(node* ptr)
{
	if (ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}


int main()
{
	node nodes[number + 1];

	for (int i = 1; i <= number; ++i)
	{
		nodes[i].data = i;
		nodes[i].leftChild = nullptr;
		nodes[i].rightChild = nullptr;
	}

	for (int i = 1; i <= number; ++i)
	{
		if (i % 2 == 0)
		{
			nodes[i / 2].leftChild = &nodes[i];
		}
		else
			nodes[i / 2].rightChild = &nodes[i];
	}

	preorder(&nodes[1]);

	return 0;
}


