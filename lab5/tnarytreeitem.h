#ifndef TNARY_TREE_ITEM_H
#define TNARY_TREE_ITEM_H

#include "rhombus.h"
#include "rectangle.h"
#include "trapezoid.h"

template <class T>
class Node
{
public:
	Node(T, int, std::shared_ptr<Node<T>>, std::shared_ptr<Node<T>>);
	int remainder;
	T t;
	std::shared_ptr<Node> parent;
	std::shared_ptr<Node> child;
	std::shared_ptr<Node> left_brother;
	std::shared_ptr<Node> right_brother;
	void PrintSubTree(std::ostream& os);
	template <typename A>
	friend std::ostream& operator<<(std::ostream&, const Node<A>&);
	virtual ~Node();
	std::shared_ptr<Node<T>> getChild();
	std::shared_ptr<Node<T>> getBrother();
	std::shared_ptr<Node<T>> getParent();
};
#endif