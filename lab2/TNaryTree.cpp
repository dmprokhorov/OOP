#include "TNaryTree.h"
TNaryTree::TNaryTree(int N, Rectangle rectangle)
{
	this->root = new Node(N, rectangle, nullptr);
}

bool TNaryTree::check_root()
{
	if (!root)
	{
		std::cout << "Attention! There is no root in tree, if you want to continue interact with tree, input degree of the tree and points of rectangle, it all will contain the new root\n";
		return false;
	}
	return true;
}

Node*& TNaryTree::get_root()
{
	return this->root;
}

void TNaryTree::set_new_root(int N, Rectangle rectangle)
{
	root->delete_sons();
	root->N = N;
	root->number = 0;
	root->size = 1;
	root->sons = new Node * [root->size];	
	root->rectangle = rectangle;
}

void TNaryTree::add_son(Rectangle parent_rectangle, Rectangle child_rectangle)
{
	if (check_root())
	{
		if (parent_rectangle == root->rectangle)
		{
			root->add_son(child_rectangle);
			return;
		}
		Node* node = search_node(root, parent_rectangle);
		if (node)
		{
			node->add_son(child_rectangle);
		}
		else
		{
			std::cout << "There is no such a node in the tree" << std::endl;
		}
	}
}

void TNaryTree::delete_node(Rectangle rectangle)
{
	if (check_root())
	{
		if (rectangle == root->rectangle)
		{
			root->delete_node();
			std::cout << "Attention! You deleted the root of the tree, so now you should init it again" << std::endl << "Input degree of the tree and root rectangle" << std::endl;
			int N; Rectangle rectangle;
			std::cin >> N >> rectangle;
			set_new_root(N, rectangle);
			return;
		}
		Node* node = search_node(root, rectangle);
		if (node)
		{
			node->delete_node();
		}
		else
		{
			std::cout << "There is no such a node in the tree" << std::endl;
		}
	}
}

Node* TNaryTree::search_node(Node*& current_node, Rectangle rectangle)
{
	Node* result;
	if (current_node->rectangle == rectangle)
	{
		return current_node;
	}
	for (int i = 0; i < current_node->number; i++)
	{
		if ((result = search_node(current_node->sons[i], rectangle)) != nullptr)
		{
			return result;
		}
	}
	return nullptr;
}

void TNaryTree::Print(Node* node)
{
	for (int i = 0; i < node->number; i++)
	{
		Print(node->sons[i]);
	}
	std::cout << node->rectangle;
}

TNaryTree::~TNaryTree()
{
	root->delete_sons();
	delete root;
}