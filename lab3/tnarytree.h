#ifndef TNARYTREE_H
#define TNARYTREE_H
#include "rectangle.h"
#include <exception>
#include <string>

class TNaryTree
{
private:
	struct Node
	{
		TNaryTree::Node(Rectangle rectangle, int remainder, std::shared_ptr<Node> parent, std::shared_ptr<Node> left_brother);
		int remainder;
		Rectangle rectangle;
		std::shared_ptr<Node> parent;
		std::shared_ptr<Node> child;
		std::shared_ptr<Node> left_brother;
		std::shared_ptr<Node> right_brother;
		~Node();
	};
	std::shared_ptr<Node> root;
	int N;
public:
	TNaryTree();
	TNaryTree(int);
	TNaryTree(TNaryTree&);
	void BuildTree(std::shared_ptr<Node>&, std::shared_ptr<Node>);
	void Update(Rectangle&&, std::string&& = "");
	void RemoveSubTree(std::string&& = "");
	void DeleteSons(std::shared_ptr<Node>&);
	Rectangle getItem(std::string&& = "");
	bool Empty();
	double Area(std::string && = "");
	double AreaOfSubtree(std::shared_ptr<Node>);
	friend std::ostream& operator<<(std::ostream&, TNaryTree&);
	friend void PrintNode(std::ostream&, std::shared_ptr<TNaryTree::Node>);
	virtual ~TNaryTree();
};
#endif
