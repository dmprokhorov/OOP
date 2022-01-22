#include <iostream>
#include "tnarytree.h"
int main()
{
    TNaryTree<Rectangle> t1(4);
    std::cout << t1 << "\n";
    t1.Update(Rectangle(std::cin), 0, "");
    t1.Update(Rectangle(std::cin), 0);
    std::cout << t1 << "\n";
    t1.Update(Rectangle(std::cin), 2, "c");
    t1.Update(Rectangle(std::cin), 0, "c");
    t1.Update(Rectangle(std::cin), 1, "c");
    t1.Update(Rectangle(std::cin), 2, "c");
    std::cout << t1 << "\n";
    t1.Update(Rectangle(std::cin), 4, "c");
    t1.Update(Rectangle(std::cin), 3, "c");
    std::cout << t1.getItem("c");
    std::cout << t1 << "\n";
    t1.Update(Rectangle(std::cin), 0, "cb");
    t1.Update(Rectangle(std::cin), 1, "cb");
    t1.Update(Rectangle(std::cin), 2, "cb");
    t1.Update(Rectangle(std::cin), 3, "cb");
    std::cout << t1 << "\n";
    t1.Update(Rectangle(std::cin), 0, "cbc");
    t1.Update(Rectangle(std::cin), 1, "cbc");
    t1.Update(Rectangle(std::cin), 2, "cbc");
    t1.Update(Rectangle(std::cin), 2, "cbc");
    t1.Update(Rectangle(std::cin), 3, "cbc");
    std::cout << t1 << "\n";
    t1.Update(Rectangle(std::cin), 0, "cbb");
    t1.Update(Rectangle(std::cin), 1, "cbb");
    t1.Update(Rectangle(std::cin), 2, "cbb");
    t1.Update(Rectangle(std::cin), 3, "cbb");
    std::cout << t1 << "\n";
    t1.Update(Rectangle(std::cin), 4, "cbb");
    t1.Update(Rectangle(std::cin), 5, "cbb");
    t1.Update(Rectangle(std::cin), 7, "cbb");
    t1.Update(Rectangle(std::cin), 6, "cbb");
    std::cout << t1 << "\n";
    t1.Update(Rectangle(std::cin), 0, "cbbb");

    t1.Remove(false, "cbb", 6);
    t1.Remove(false, "cb", 2);
    std::cout << t1 << "\n";

    t1.Remove(false, "c", 2);
    t1.Remove(false, "cbb", 3);
    t1.Remove(false, "cb", 0);
    std::cout << t1 << "\n";
    t1.Remove(true, "cb");
    std::cout << t1 << "\n";
    t1.Remove(true);
    std::cout << t1 << "\n";
    system("pause");
    return 0;
}
