// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "TNaryTree.h"
int main()
{
    std::cout << "Input degree of the tree and root rectangle" << std::endl;
    int N;
    Rectangle rectangle;
    std::cin >> N >> rectangle;
    TNaryTree tree(N, rectangle);
    char command;
    while ((std::cin >> command) && (command != 'c'))
    {
        switch (command)
        {
            case 'a':
            {
                Rectangle rec_parent, rec_child;
                std::cin >> rec_parent >> rec_child;
                tree.add_son(rec_parent, rec_child);
                break;
            }
            case 'd':
            {
                Rectangle rec_node;
                std::cin >> rec_node;
                tree.delete_node(rec_node);
                break;
            }
            case 'p':
            {
                if (tree.check_root())
                {
                    tree.Print(tree.get_root());
                }
                break;
            }
            case 'r':
            {
                if (tree.get_root())
                {
                    std::cin >> N >> rectangle;
                    tree.set_new_root(N, rectangle);
                    break;
                }
            }
        }
    }
    system("pause");
    return 0;
}

