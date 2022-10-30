#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <memory>

using namespace std;

using NodeRef = shared_ptr<struct Node>;

struct Node
{
	Node(){}
	Node(const string& _data)
		:data(_data){}

	string		    data;
	vector<NodeRef> children;
};

NodeRef CreateTree()
{
	NodeRef root = make_shared<Node>("R1 ���߽�");
	{
		NodeRef node = make_shared<Node>("��������");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("����");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("����");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("���丮");
			node->children.push_back(leaf);
		}

		NodeRef node2 = make_shared<Node>("���α׷�����");
		root->children.push_back(node2);
		{
			NodeRef leaf = make_shared<Node>("����");
			node2->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("Ŭ��");
			node2->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("����");
			node2->children.push_back(leaf);
		}
		
		NodeRef node3 = make_shared<Node>("��Ʈ��");
		root->children.push_back(node3);
		{
			NodeRef leaf = make_shared<Node>("���");
			node3->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("ĳ����");
			node3->children.push_back(leaf);
		}
	}
	return root;
}

void PrintTree(NodeRef root,int depth)
{
	for (int i = 0; i < depth; ++i)
		cout << "-";
	cout << root->data << endl;

	for (NodeRef& child : root->children)
		PrintTree(child,depth+1);
}

// ����(depth)  : ��Ʈ���� � ��忡 �����ϱ����� ���ľ� �ϴ� ������ �� (����?)
// ����(height) : ���� ����� �ִ� ����� ����(MAX(depth))

int GetHeight(NodeRef root)
{
	int height = 1;

	for (NodeRef& child : root->children)
	{
		height = max(height,GetHeight(child) + 1); // ���� ���� ����
	}

	return height;
}


int main()
{
	NodeRef root = CreateTree();

	PrintTree(root,0);

	cout << GetHeight(root) << endl;
}