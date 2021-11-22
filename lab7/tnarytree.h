#ifndef TNARYTREE_H
#define TNARYTREE_H
#include"tnarytreeitem.h"
#include <exception>
#include <string>

template<class T>
class TNaryTree
{
private:
	std::shared_ptr<Node<T>> root;
	int N;
	int amount;
public:
	TNaryTree();
	TNaryTree(int);
	TNaryTree(TNaryTree<T>&);
	void BuildTree(std::shared_ptr<Node<T>>&, std::shared_ptr<Node<T>>);
	void Update(T&&, int, std::string && = "");
	void Remove(bool, std::string && = "", int index = 0);
	void DeleteSons(std::shared_ptr<Node<T>>&);
	TVector<T> getItem(std::string && = "");
	bool Empty();
	/*
	double Area(std::string && = "");
	double AreaOfSubtree(std::shared_ptr<Node<T>>);*/
	template <typename A>
	friend std::ostream& operator<<(std::ostream&, TNaryTree<A>&);
	virtual ~TNaryTree();
};
#endif
