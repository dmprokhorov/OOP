#include "tnarytree.h"

TNaryTree::TNaryTree()
{
	this->N = 2;
	root = std::make_shared<Node>(Node(Rectangle(), 0, nullptr, nullptr));
}
TNaryTree::TNaryTree(int N)
{
	this->N = N;
	root = std::make_shared<Node>(Node(Rectangle(), 0, nullptr, nullptr));
}

TNaryTree::TNaryTree(TNaryTree& other)
{
	N = other.N;
	if (other.Empty())
	{
		root = nullptr;
		return;
	}
	root = std::make_shared<Node>(Node(other.root->rectangle, 0, nullptr, nullptr));
	BuildTree(root, other.root);
}

void TNaryTree::BuildTree(std::shared_ptr<Node>& current_node, std::shared_ptr<Node> other_node)
{
	if (!other_node->child)
	{
		return;
	}
	current_node->child = std::make_shared<Node>(Node(other_node->child->rectangle, other_node->child->remainder, current_node, nullptr));
	std::shared_ptr<Node>copy = current_node->child, other_copy = other_node->child;
	while (other_copy)
	{
		BuildTree(copy, other_copy);
		if (other_copy->right_brother)
		{
			copy->right_brother = std::make_shared<Node>(Node(other_copy->right_brother->rectangle, other_copy->right_brother->remainder, current_node, copy));
		}
		else
		{
			copy->right_brother = nullptr;
		}
		copy = copy->right_brother;
		other_copy = other_copy->right_brother;
	}
}

TNaryTree::Node::Node(Rectangle rectangle, int remainder, std::shared_ptr<Node> parent, std::shared_ptr<Node> left_brother)
{
	this->rectangle = rectangle;
	this->remainder = remainder;
	this->parent = parent;
	this->child = child;
	this->left_brother = left_brother;
	this->right_brother = right_brother;
}

TNaryTree::Node::~Node() {}

bool TNaryTree::Empty()
{
	if (root)
	{
		return false;
	}
	return true;
}

void TNaryTree::Node::abn()
{

}

Rectangle TNaryTree::getItem(std::string&& tree_path)
{
	try
	{
		if (!tree_path.length())
		{
			if (Empty())
			{
				throw std::invalid_argument("There's no root\n");
			}
			else
			{
				return root->rectangle;
			}
		}
		std::shared_ptr<Node> current_node = root;
		while (tree_path.length())
		{
			switch (tree_path[0])
			{
				case 'b':
				{
					if (!current_node)
					{
						throw std::invalid_argument("There's no such element in tree\n");
					}
					current_node = current_node->right_brother;
					break;
				}
				case 'c':
				{
					if (!current_node)
					{
						throw std::invalid_argument("There's no such element in tree\n");
					}
					current_node = current_node->child;
					break;
				}
				default:
				{
					throw std::invalid_argument("String must contain only 'b' or 'c' characters\n");
				}
			}
			tree_path.erase(tree_path.begin());
		}
		if (!current_node)
		{
			throw std::invalid_argument("There's no such element in tree\n");
		}
		return current_node->rectangle;
	}
	catch (std::invalid_argument& error)
	{
		std::cout << error.what();
		return Rectangle();
	}
	catch (std::out_of_range& error)
	{
		std::cout << error.what();
		return Rectangle();
	}
}

void TNaryTree::Update(Rectangle&& rectangle, std::string&& tree_path)
{
	try
	{
		if (!tree_path.length())
		{
			if (Empty())
			{
				root = std::make_shared<Node>(Node(rectangle, 0, nullptr, nullptr));
			}
			else
			{
				root->rectangle = rectangle;
			}
			return;
		}
		std::shared_ptr<Node> current_node = root;
		while (tree_path.length() > 1)
		{
			switch (tree_path[0])
			{
				case 'b':
				{
					if (!current_node)
					{
						throw std::invalid_argument("There's no such element in tree\n");
					}
					current_node = current_node->right_brother;
					break;
				}
				case 'c':
				{
					if (!current_node)
					{
						throw std::invalid_argument("There's no such element in tree\n");
					}
					current_node = current_node->child;
					break;
				}
				default:
				{
					throw std::invalid_argument("String must contain only 'b' or 'c' characters\n");
				}
			}
			tree_path.erase(tree_path.begin());
		}
		switch (tree_path[0])
		{
			case 'b':
			{
				if ((!current_node) || (!current_node->remainder))
				{
					throw std::out_of_range("Node already has " + std::to_string(N) + " sons, so it's imposible to add another one\n");
				}
				if (!current_node->right_brother)
				{
					current_node->right_brother = std::make_shared<Node>(Node(rectangle, current_node->remainder - 1, current_node->parent, current_node));
				}
				else
				{
					current_node->rectangle = rectangle;
				}
				break;
			}
			case 'c':
			{
				if (!current_node)
				{
					throw std::invalid_argument("There's no such element in tree\n");
				}
				if (!current_node->child)
				{
					current_node->child = std::make_shared<Node>(Node(rectangle, N - 1, current_node, nullptr));
				}
				else
				{
					current_node->child->rectangle = rectangle;
				}
				break;
			}
			default:
			{
				throw std::invalid_argument("String must contain only 'b' or 'c' characters\n");
			}
		}
		tree_path.erase(tree_path.begin());
	}
	catch (std::invalid_argument& error)
	{
		std::cout << error.what();
		return;
	}
	catch (std::out_of_range& error)
	{
		std::cout << error.what();
		return;
	}
}

void TNaryTree::DeleteSons(std::shared_ptr<Node>& node)
{
	std::shared_ptr<Node> copy = node->child, previous = copy;
	while (copy)
	{
		if (copy->child)
		{
			DeleteSons(copy);
		}
		previous = copy;
		copy = copy->right_brother;
	}
	while (previous)
	{
		previous->right_brother = nullptr;
		previous = previous->left_brother;
	}
	node->child = nullptr;
	//previous->parent->child = nullptr;
}

void TNaryTree::RemoveSubTree(std::string&& tree_path)
{
	try
	{
		if (!tree_path.length())
		{
			if (Empty())
			{
				throw std::invalid_argument("The root is empty\n");
			}
			else
			{
				DeleteSons(root);
				root = nullptr;
				return;
			}
		}
		std::shared_ptr<Node> current_node = root;
		while (tree_path.length())
		{
			switch (tree_path[0])
			{
				case 'b':
				{
					if (!current_node)
					{
						throw std::invalid_argument("There's no such element in tree\n");
					}
					current_node = current_node->right_brother;
					break;
				}
				case 'c':
				{
					if (!current_node)
					{
						throw std::invalid_argument("There's no such element in tree\n");
					}
					current_node = current_node->child;
					break;
				}
				default:
				{
					throw std::invalid_argument("String must contain only 'b' or 'c' characters\n");
				}
			}
			tree_path.erase(tree_path.begin());
		}
		if (!current_node)
		{
			throw std::invalid_argument("There's no such element in tree\n");
		}
		DeleteSons(current_node);
		std::shared_ptr<Node> clone = current_node->right_brother;
		if (current_node->left_brother)
		{
			if (current_node->right_brother)
			{
				current_node->right_brother->left_brother = current_node->left_brother;
			}
			current_node->left_brother->right_brother = current_node->right_brother;
		}
		else
		{
			current_node->parent->child = current_node->right_brother;
		}
		current_node = nullptr;
		while (clone)
		{
			++(clone->remainder);
			clone = clone->right_brother;
		}
	}
	catch (std::invalid_argument& error)
	{
		std::cout << error.what();
		return;
	}
	catch (std::out_of_range& error)
	{
		std::cout << error.what();
		return;
	}
}

double TNaryTree::AreaOfSubtree(std::shared_ptr<Node> node)
{
	double S = node->rectangle.Square();
	std::shared_ptr<Node> current_node = node->child;
	while (current_node)
	{
		S += AreaOfSubtree(current_node);
		current_node = current_node->right_brother;
	}
    return S;
}

double TNaryTree::Area(std::string&& tree_path)
{
	try
	{
		if (Empty())
		{
			throw std::invalid_argument("The root is empty\n");
		}
		if (!tree_path.length())
		{
			return AreaOfSubtree(root);
		}
		std::shared_ptr<Node> current_node = root;
		while (tree_path.length())
		{
			switch (tree_path[0])
			{
				case 'b':
				{
					if (!current_node)
					{
						throw std::invalid_argument("There is no such element in tree\n");
					}
					current_node = current_node->right_brother;
					tree_path.erase(tree_path.begin());
					break;
				}
				case 'c':
				{
					if (!current_node)
					{
						throw std::invalid_argument("There is no such element in tree\n");
					}
					current_node = current_node->child;
					tree_path.erase(tree_path.begin());
					break;
				}
				default:
				{
					throw std::invalid_argument("String must contain only 'b' or 'c' characters\n");
				}
			}
			tree_path.erase(tree_path.begin());
		}
		if (!current_node)
		{
			throw std::invalid_argument("There's no such element in tree\n");
		}
		return AreaOfSubtree(current_node);
	}
	catch (std::invalid_argument& error)
	{
		std::cout << error.what();
		return -1.;
	}
	catch (std::out_of_range& error)
	{
		std::cout << error.what();
		return -1.;
	}
}

void PrintNode(std::ostream& os, std::shared_ptr<TNaryTree::Node> node)
{
	os << node->rectangle.Square();
	if (!node->child)
	{
		return;
	}
	std::shared_ptr<TNaryTree::Node> current_node = node->child;
	os << ": [";
	while (current_node)
	{
		PrintNode(os, current_node);
		if (current_node->right_brother)
		{
			os << ", ";
		}
		current_node = current_node->right_brother;
	}
	os << "]";
}

std::ostream& operator<<(std::ostream& os, TNaryTree& tree)
{
	try
	{
		if (tree.Empty())
		{
			throw std::invalid_argument("The root is empty");
		}
		PrintNode(os, tree.root);
	}
	catch (std::invalid_argument& error)
	{
		os << error.what();
	}
	os << "\n";
	return os;
};

TNaryTree::~TNaryTree()
{
	if (!Empty())
	{
		DeleteSons(root);
		root = nullptr;
	}
}