#include "Node.h"

Node::Node(int N, Rectangle rectangle, Node* parent) : N(N), rectangle(rectangle), number(0), size(1), sons(new Node* [size]), parent(parent) 
{
};

int Node::get_number()
{
	return number;
}

Rectangle Node::get_rectangle()
{
	return rectangle;
}

Node** Node::get_sons()
{
	return sons;
}


void Node::add_son(Rectangle rectangle)
{
	if (number == N)
	{
		std::cout << "This node already has " << N << " sons, so it is impossible to add another one" << std::endl;
		return;
	}
	if (number == size)
	{
		size = std::min(N, size * 2);
		Node** new_sons = new Node*[size];
		for (int i = 0; i < number; i++)
		{
			new_sons[i] = sons[i];
		}
		delete[] sons;
		this->sons = new_sons;
		sons[number] = new Node(N, rectangle, this);
	}
	else
	{
		sons[number] = new Node(N, rectangle, this);
	}
	number++;
}

void Node::delete_node()
{
	if (!parent)
	{
		return;
	}
	for (int i = 0; i < parent->number; i++)
	{
		if (parent->sons[i] == this)
		{
			this->delete_sons();
			for (int j = i + 1; j < parent->number; j++)
			{
				parent->sons[j - 1] = parent->sons[j];
			}
			if (--(parent->number))
			{
				if (parent->number * 2 <= parent->size)
				{
					(parent->size) /= 2;
				}
				Node** new_sons = new Node * [parent->size];
				for (int i = 0; i < parent->number; i++)
				{
					new_sons[i] = parent->sons[i];
				}
				delete[] parent->sons;
				parent->sons = new_sons;
			}
			else
			{
				delete[] parent->sons;
			}
			break;
		}
	}
}

void Node::delete_sons()
{
	for (int i = 0; i < number; i++)
	{
		sons[i]->delete_sons();
		delete sons[i];
	}
	delete[] sons;
	this->~Node();
}

Node::~Node()
{

}