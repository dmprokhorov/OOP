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
		Node(Rectangle rectangle, Node* parent, int number, int size);
		int number, size;
		Rectangle rectangle;
		Node** sons;
		Node* parent;
		~Node();
	};
	Node* root;
	int N;
public:
	TNaryTree();
	TNaryTree(int);
	TNaryTree(TNaryTree&);
	void BuildTree(Node*&, const Node*);
	void Update(Rectangle&&, std::string&&="");
	void Clear(std::string&&="");
	void DeleteSons(Node*&);
	bool Empty();
	double Area(std::string&&="");
	double AreaOfSubtree(Node*);
	friend std::ostream& operator<<(std::ostream&, TNaryTree&);
	friend void PrintNode(std::ostream&, TNaryTree::Node*);
	virtual ~TNaryTree();
};
#endif
