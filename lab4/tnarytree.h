#ifndef TNARYTREE_H
#define TNARYTREE_H
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"
#include <exception>
#include <string>

template<class T>
class TNaryTree
{
private:
	struct Node
	{
		Node(T, int, std::shared_ptr<Node>, std::shared_ptr<Node>);
		int remainder;
		T t;
        std::shared_ptr<Node> parent;
		std::shared_ptr<Node> child;
		std::shared_ptr<Node> left_brother;
		std::shared_ptr<Node> right_brother;
		void PrintSubTree(std::ostream& os);
        ~Node();
	};
	std::shared_ptr<Node> root;
	int N;
public:
	TNaryTree();
	TNaryTree(int);
	TNaryTree(TNaryTree<T>&);
	void BuildTree(std::shared_ptr<Node>&, std::shared_ptr<Node>);
	void Update(T&&, std::string && = "");
	void RemoveSubTree(std::string && = "");
	void DeleteSons(std::shared_ptr<Node>&);
	T getItem(std::string && = "");
	bool Empty();
	double Area(std::string && = "");
	double AreaOfSubtree(std::shared_ptr<Node>);
	template <typename A>
	friend std::ostream& operator<<(std::ostream&, TNaryTree<A>&);
	/*template <typename A>
	friend void PrintNode(std::ostream&, std::shared_ptr<typename TNaryTree<A>::Node>);*/
	virtual ~TNaryTree();
};
#endif