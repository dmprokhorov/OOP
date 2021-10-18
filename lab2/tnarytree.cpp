#include "tnarytree.h"
TNaryTree::TNaryTree()
{
	this->N = 0;
	root = new Node(Rectangle(), nullptr, 0, 1);
}
TNaryTree::TNaryTree(int N)
{
	this->N = N;
	root = new Node(Rectangle(), nullptr, 0, 1);
}

TNaryTree::TNaryTree(TNaryTree& other)
{
	N = other.N;
	if (other.Empty())
	{
		root = nullptr;
		return;
	}
	root = new Node(other.root->rectangle, nullptr, other.root->number, other.root->size);
    BuildTree(root, other.root);
}

void TNaryTree::BuildTree(Node*& current_node, const Node* other_node)
{
	for (int i = 0; i < other_node->number; i++)
	{
		current_node->sons[i] = new Node(other_node->sons[i]->rectangle, current_node, other_node->sons[i]->number, other_node->sons[i]->size);
		BuildTree(current_node->sons[i], other_node->sons[i]);
	}
}

TNaryTree::Node::Node(Rectangle rectangle, Node* parent, int number, int size) : rectangle(rectangle), number(number), size(size), sons(new Node* [size]), parent(parent)
{

}

TNaryTree::Node::~Node()
{

}

bool TNaryTree::Empty()
{
	if (root)
	{
		return false;
	}
	return true;
}

Rectangle TNaryTree::getItem(std::string&& tree_path)
{
	try
	{
		if (Empty())
		{
			throw std::invalid_argument("The root is empty\n");
		}
		if (!tree_path.length())
		{
			return root->rectangle;
		}
		/*if ((Empty()) && (tree_path.length()))
		{

		}
		if (!tree_path.length())
		{
			if (Empty())
			{
				std::cout << "There is no root, so input N" << std::endl;
				int N;
				this->N = N;
				root = new Node(rectangle, nullptr);
			}
			root->rectangle = rectangle;
			return;
		}*/
		if (tree_path[0] == 'b')
		{
			throw std::invalid_argument("There is no such element in tree\n");
		}
		int current_number = 0, number = root->number;
		Node* current_node = root;
		while (tree_path.length())
		{
			switch (tree_path[0])
			{
				case 'b':
				{
					if (current_number == N - 1)
					{
						throw std::out_of_range("Node already has " + std::to_string(N) + " sons\n");
					}
					else if (current_number == number - 1)
					{
						throw std::invalid_argument("There is no such element in tree\n");
					}
					current_node = current_node->parent->sons[++current_number];
					tree_path.erase(tree_path.begin());
					break;
				}
				case 'c':
				{
					if (!current_node->number)
					{
						throw std::invalid_argument("There is no such element in tree\n");
					}
					number = current_node->number;
					current_node = current_node->sons[0];
					current_number = 0;
					tree_path.erase(tree_path.begin());
					break;
				}
				default:
				{
					throw std::invalid_argument("String must contain only 'b' or 'c' characters\n");
				}
			}
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
		if (Empty())
		{
			if (tree_path.length())
			{
				throw std::invalid_argument("The root is empty\n");
			}
			else
			{
				std::cout << "There is no root, so input N" << std::endl;
				int N;
				std::cin >> N;
				this->N = N;
				root = new Node(rectangle, nullptr, 0, 1);
				return;
			}
		}
		if (!tree_path.length())
		{
			root->rectangle = rectangle;
			return;
		}
		/*if ((Empty()) && (tree_path.length()))
		{
			
		}
		if (!tree_path.length())
		{
			if (Empty())
			{
				std::cout << "There is no root, so input N" << std::endl;
				int N;
				this->N = N;
				root = new Node(rectangle, nullptr);
			}
			root->rectangle = rectangle;
			return;
		}*/
		if (tree_path[0] == 'b')
		{
			throw std::invalid_argument("There is no such element in tree\n");
		}
		int current_number = 0, number = root->number;
		Node* current_node = root;
		while (tree_path.length() > 1)
		{
			switch (tree_path[0])
			{
				case 'b':
				{
					if (current_number == N - 1)
					{
						throw std::out_of_range("Node already has " + std::to_string(N) + " sons\n");
					}
					else if (current_number == number - 1)
					{
						throw std::invalid_argument("There is no such element in tree\n");
					}
					current_node = current_node->parent->sons[++current_number];
					tree_path.erase(tree_path.begin());
					break;
				}
				case 'c':
				{
					if (!current_node->number)
					{
						throw std::invalid_argument("There is no such element in tree\n");
					}
					number = current_node->number;
					current_node = current_node->sons[0];
					current_number = 0;
					tree_path.erase(tree_path.begin());
					break;
				}
				default:
				{
					throw std::invalid_argument("String must contain only 'b' or 'c' characters\n");
				}
			}
		}
		if (tree_path[0] == 'b')
		{
			if (current_number == N - 1)
			{
				throw std::out_of_range("Node already has " + std::to_string(N) + " sons\n");
			}
			if (current_number == number - 1)
			{
				if (current_node->parent->size == number)
				{
					current_node->parent->size = std::min(N, current_node->parent->size * 2);
					Node** new_sons = new Node* [current_node->parent->size];
					for (int i = 0; i < number; i++)
					{
						new_sons[i] = current_node->parent->sons[i];
					}
					delete[] current_node->parent->sons;
					current_node->parent->sons = new_sons;
				}
				current_node->parent->sons[number] = new Node(rectangle, current_node->parent, 0, 1);
				current_node->parent->number++;
			}
			else
			{
				current_node->parent->sons[++current_number]->rectangle = rectangle;
			}
		}
		else if (tree_path[0] == 'c')
		{
			if (!current_node->number)
			{
				current_node->sons[0] = new Node(rectangle, current_node, 0, 1);
				current_node->number = 1;
			}
			else
			{
				current_node->sons[0]->rectangle = rectangle;
			}
		}
		else
		{
			throw std::invalid_argument("String must contain only 'b' or 'c' characters\n");
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

void TNaryTree::DeleteSons(Node*& node)
{
	for (int i = 0; i < node->number; i++)
	{
		DeleteSons(node->sons[i]);
		delete node->sons[i];
	}
	delete[] node->sons;
	//node->parent = nullptr;
	node->~Node();
}

void TNaryTree::RemoveSubTree(std::string&& tree_path)
{
	try
	{
		if (Empty())
		{
			throw std::invalid_argument("The root is empty\n");
			return;
		}
		if (!tree_path.length())
		{
			DeleteSons(root);
			//delete[] root->sons;

			delete root;
			root = nullptr;
			return;
		}
		if (tree_path[0] == 'b')
		{
			throw std::invalid_argument("There is no such element in tree\n");
		}
		int current_number = 0, number = root->number;
		Node* current_node = root;
		while (tree_path.length())
		{
			switch (tree_path[0])
			{
				case 'b':
				{
					if (current_number == number - 1)
					{
						throw std::invalid_argument("There is no such element in tree\n");
					}
					current_node = current_node->parent->sons[++current_number];
					tree_path.erase(tree_path.begin());
					break;
				}
				case 'c':
				{
					if (!current_node->number)
					{
						throw std::invalid_argument("There is no such element in tree\n");
					}
					number = current_node->number;
					current_node = current_node->sons[0];
					current_number = 0;
					tree_path.erase(tree_path.begin());
					break;
				}
				default:
				{
					throw std::invalid_argument("String must contain only 'b' or 'c' characters\n");
				}
			}
		}
		DeleteSons(current_node);
		Node* parent = current_node->parent;
		delete current_node->parent->sons[current_number];
		for (int i = current_number; i < number - 1; i++)
		{
			parent->sons[i] = parent->sons[i + 1];
		}
		number--;
		if (number * 2 <= parent->size)
		{
			parent->size /= 2;
		}
		Node** new_sons = new Node* [parent->size];
		for (int i = 0; i < number; i++)
		{
			new_sons[i] = parent->sons[i];
		}
		delete[] parent->sons;
		parent->sons = new_sons;
		parent->number--;
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

double TNaryTree::AreaOfSubtree(Node* node)
{
	double S = .0;
	for (int i = 0; i < node->number; i++)
	{
		S += AreaOfSubtree(node->sons[i]);;
	}
	return S + node->rectangle.Square();
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
		if (tree_path[0] == 'b')
		{
			throw std::invalid_argument("There is no such element in tree\n");
		}
		int current_number = 0, number = root->number;
		Node* current_node = root;
		while (tree_path.length())
		{
			switch (tree_path[0])
			{
				case 'b':
				{
					if (current_number == number - 1)
					{
						throw std::invalid_argument("There is no such element in tree\n");
					}
					current_node = current_node->parent->sons[++current_number];
					tree_path.erase(tree_path.begin());
					break;
				}
				case 'c':
				{
					if (!current_node->number)
					{
						throw std::invalid_argument("There is no such element in tree\n");
					}
					number = current_node->number;
					current_node = current_node->sons[0];
					current_number = 0;
					tree_path.erase(tree_path.begin());
					break;
				}
				default:
				{
					throw std::invalid_argument("String must contain only 'b' or 'c' characters\n");
				}
			}
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

void PrintNode(std::ostream& os, TNaryTree::Node* node)
{
	if (node)
	{
		os << node->rectangle.Square();
	}
	if (!node->number)
	{
		return;
	}
	else
	{
		os << ": [";
		for (int i = 0; i < node->number; i++)
		{
			PrintNode(os, node->sons[i]);
			if (i < node->number - 1)
			{
				os << ", ";
			}
		}
		os << "]";
	}
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
		//	delete[] root->sons;
		delete root;
	}
}
