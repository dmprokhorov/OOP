#include "tnarytreeitem.h"
template Node<Rectangle>;
template Node<Rhombus>;
template Node<Trapezoid>;

template <class T> Node<T>::Node(T t, int remainder, std::shared_ptr<Node<T>> parent, std::shared_ptr<Node<T>> left_brother)
{
	vector = TVector<T>(t);
	this->remainder = remainder;
	this->parent = parent;
	this->child = child;
	this->left_brother = left_brother;
	this->right_brother = right_brother;
}

template <class T> Node<T>::Node(TVector<T> tvector, int remainder, std::shared_ptr<Node<T>> parent, std::shared_ptr<Node<T>> left_brother)
{
	vector = tvector;
	this->remainder = remainder;
	this->parent = parent;
	this->child = child;
	this->left_brother = left_brother;
	this->right_brother = right_brother;
}

template <typename T> std::shared_ptr<Node<T>> Node<T>::getChild()
{
	return this->child;
}

template <typename T> std::shared_ptr<Node<T>> Node<T>::getBrother()
{
	return this->right_brother;
}

template <typename T> std::shared_ptr<Node<T>> Node<T>::getParent()
{
	return this->parent;
}

template <class T> void Node<T>::PrintSubTree(std::ostream& os)
{
	os << *this;
	if (!this->child)
	{
		return;
	}
	std::shared_ptr<Node<T>> current_node = this->getChild();
	os << ": [";
	while (current_node)
	{
		current_node->PrintSubTree(os);
		if (current_node->getBrother())
		{
			os << ", ";
		}
		current_node = current_node->getBrother();
	}
	os << "]";
}

template std::ostream& operator<<(std::ostream& os, const Node<Rectangle>& node);
template std::ostream& operator<<(std::ostream& os, const Node<Rhombus>& node);
template std::ostream& operator<<(std::ostream& os, const Node<Trapezoid>& node);

template <typename T> std::ostream& operator<< (std::ostream& os, const Node<T>& node)
{
	os << node.vector;
	return os;
}

template<class T> Node<T>::~Node()
{

}