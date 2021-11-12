#include "tnarytree.h"

template TNaryTree<Rectangle>;
template TNaryTree<Rhombus>;
template TNaryTree<Trapezoid>;

template <class T> TNaryTree<T>::TNaryTree()
{
	this->N = 2;
	root = std::make_shared<Node<T>>(Node<T>(T(), 0, nullptr, nullptr));
}
template <class T> TNaryTree<T>::TNaryTree(int N)
{
	this->N = N;
	root = std::make_shared<Node<T>>(Node<T>(T(), 0, nullptr, nullptr));
}

template <class T> TNaryTree<T>::TNaryTree(TNaryTree& other)
{
	N = other.N;
	if (other.Empty())
	{
		root = nullptr;
		return;
	}
	root = std::make_shared<Node<T>>(Node<T>(other.root->t, 0, nullptr, nullptr));
	BuildTree(root, other.root);
}

template <class T> void TNaryTree<T>::BuildTree(std::shared_ptr<Node<T>>& current_node, std::shared_ptr<Node<T>> other_node)
{
	if (!other_node->child)
	{
		return;
	}
	current_node->child = std::make_shared<Node<T>>(Node<T>(other_node->child->t, other_node->child->remainder, current_node, nullptr));
	std::shared_ptr<Node<T>>copy = current_node->child, other_copy = other_node->child;
	while (other_copy)
	{
		BuildTree(copy, other_copy);
		if (other_copy->right_brother)
		{
			copy->right_brother = std::make_shared<Node<T>>(Node<T>(other_copy->right_brother->t, other_copy->right_brother->remainder, current_node, copy));
		}
		else
		{
			copy->right_brother = nullptr;
		}
		copy = copy->right_brother;
		other_copy = other_copy->right_brother;
	}
}

template <class T> bool TNaryTree<T>::Empty()
{
	if (root)
	{
		return false;
	}
	return true;
}


template<class T> T TNaryTree<T>::getItem(std::string&& tree_path)
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
				return root->t;
			}
		}
		std::shared_ptr<Node<T>> current_node = root;
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
		return current_node->t;
	}
	catch (std::invalid_argument& error)
	{
		std::cout << error.what();
		return T();
	}
	catch (std::out_of_range& error)
	{
		std::cout << error.what();
		return T();
	}
}

template <class T> void TNaryTree<T>::Update(T&& t, std::string&& tree_path)
{
	try
	{
		if (!tree_path.length())
		{
			if (Empty())
			{
				root = std::make_shared<Node<T>>(Node<T>(t, 0, nullptr, nullptr));
			}
			else
			{
				root->t = t;
			}
			return;
		}
		std::shared_ptr<Node<T>> current_node = root;
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
				current_node->right_brother = std::make_shared<Node<T>>(Node<T>(t, current_node->remainder - 1, current_node->parent, current_node));
			}
			else
			{
				current_node->t = t;
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
				current_node->child = std::make_shared<Node<T>>(Node<T>(t, N - 1, current_node, nullptr));
			}
			else
			{
				current_node->child->t = t;
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

template <class T> void TNaryTree<T>::DeleteSons(std::shared_ptr<Node<T>>& node)
{
	std::shared_ptr<Node<T>> copy = node->child, previous = copy;
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
}

template <class T> void TNaryTree<T>::RemoveSubTree(std::string&& tree_path)
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
		std::shared_ptr<Node<T>> current_node = root;
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
		std::shared_ptr<Node<T>> clone = current_node->right_brother;
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

template <class T> double TNaryTree<T>::AreaOfSubtree(std::shared_ptr<Node<T>> node)
{
	double S = node->t.Square();
	std::shared_ptr<Node<T>> current_node = node->child;
	while (current_node)
	{
		S += AreaOfSubtree(current_node);
		current_node = current_node->right_brother;
	}
	return S;
}

template <class T> double TNaryTree<T>::Area(std::string&& tree_path)
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
		std::shared_ptr<Node<T>> current_node = root;
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

template std::ostream& operator<<(std::ostream& os, TNaryTree<Rectangle>& tree);
template std::ostream& operator<<(std::ostream& os, TNaryTree<Rhombus>& tree);
template std::ostream& operator<<(std::ostream& os, TNaryTree<Trapezoid>& tree);

template <typename T> std::ostream& operator<<(std::ostream& os, TNaryTree<T>& tree)
{
	try
	{
		if (tree.Empty())
		{
			throw std::invalid_argument("The root is empty");
		}
		std::shared_ptr<Node<T>> current_node = tree.root;
		tree.root->PrintSubTree(os);
	}
	catch (std::invalid_argument& error)
	{
		os << error.what();
	}
	os << "\n";
	return os;
};

template <class T> TNaryTree<T>::~TNaryTree()
{
	if (!Empty())
	{
		DeleteSons(root);
		root = nullptr;
	}
}