#ifndef TNARYTREE_H
#define TNARYTREE_H
#include "Node.h"
class TNaryTree
{
public:
	TNaryTree(int N, Rectangle rectangle);
	Node*& get_root();
	void set_new_root(int N, Rectangle rectangle);
	bool check_root();
	void add_son(Rectangle parent_rectangle, Rectangle child_rectangle);
	void delete_node(Rectangle rectangle);
	Node* search_node(Node*& current_node, Rectangle rectangle);
	void Print(Node* node);
	~TNaryTree();
private:
	Node* root;
};
#endif
