#ifndef NODE_H
#define NODE_H
#include "Rectangle.h"
class Node
{
public:
	Node(int N, Rectangle rectangle, Node* parent);
	void add_son(Rectangle rectangle);
	void delete_node();
	void delete_sons();
	int get_number();
	Node** get_sons();
	Rectangle get_rectangle();
	~Node();
	int N, number, size;
	Rectangle rectangle;
	Node** sons;
	Node* parent;
};
#endif
