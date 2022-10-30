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
	NodeRef root = make_shared<Node>("R1 개발실");
	{
		NodeRef node = make_shared<Node>("디자인팀");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("전투");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("경제");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("스토리");
			node->children.push_back(leaf);
		}

		NodeRef node2 = make_shared<Node>("프로그래밍팀");
		root->children.push_back(node2);
		{
			NodeRef leaf = make_shared<Node>("서버");
			node2->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("클라");
			node2->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("앤진");
			node2->children.push_back(leaf);
		}
		
		NodeRef node3 = make_shared<Node>("아트팀");
		root->children.push_back(node3);
		{
			NodeRef leaf = make_shared<Node>("배경");
			node3->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("캐릭터");
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

// 깊이(depth)  : 루트에서 어떤 노드에 도달하기위해 거쳐야 하는 간선의 수 (몇층?)
// 높이(height) : 가장 깊숙히 있는 노드의 깊이(MAX(depth))

int GetHeight(NodeRef root)
{
	int height = 1;

	for (NodeRef& child : root->children)
	{
		height = max(height,GetHeight(child) + 1); // 현재 나의 높이
	}

	return height;
}


int main()
{
	NodeRef root = CreateTree();

	PrintTree(root,0);

	cout << GetHeight(root) << endl;
}