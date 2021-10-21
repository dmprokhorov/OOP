// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//#include <sstream>
#include "tnarytree.h"
int main()
{
    double S = 0.;
    std::string string;
    TNaryTree<Rectangle> t1(3);
    std::cout << t1;
    t1.Update(Rectangle(std::cin), "cbc");
    t1.Update(Rectangle(std::cin), "");
    t1.Update(Rectangle(std::cin));
    t1.Update(Rectangle(std::cin), "c");
    t1.Update(Rectangle(std::cin), "cb");
    std::cout << t1.getItem("cb");
    std::cout << t1.getItem("cbb");
    t1.Update(Rectangle(std::cin), "cc");
    t1.Update(Rectangle(std::cin), "cbb");
    std::cout << t1;
    t1.Update(Rectangle(std::cin), "cbbb");
    if (((S = t1.Area()) == -1))
    {
        std::cout << "There is no such element in tree" << std::endl;
    }
    else
    {
        std::cout << "Area of subtree is " << S << std::endl;
    }
    if (((S = t1.Area("cbbcccbc")) == -1))
    {
        std::cout << "There is no such element in tree" << std::endl;
    }
    else
    {
        std::cout << "Area of subtree is " << S << std::endl;
    }
    t1.Update(Rectangle(std::cin), "cbc");
    std::cout << t1;
    t1.Update(Rectangle(std::cin), "ccb");
    t1.Update(Rectangle(std::cin), "ccbb");
    t1.Update(Rectangle(std::cin), "cbcb");
    t1.Update(Rectangle(std::cin), "cbcbb");
    std::cout << t1;
    if (((S = t1.Area("c")) == -1))
    {
        std::cout << "There is no such element in tree" << std::endl;
    }
    else
    {
        std::cout << "Area of subtree is " << S << std::endl;
    }
    t1.Update(Rectangle(std::cin), "cbbbc");
    std::cout << t1;
    t1.Update(Rectangle(std::cin), "cbbc");
    t1.Update(Rectangle(std::cin), "cbb");
    std::cout << t1;
    t1.Update(Rectangle(std::cin), "cbbcb");
    t1.Update(Rectangle(std::cin), "cbbcbb");
    t1.Update(Rectangle(std::cin), "ccbc");
    t1.Update(Rectangle(std::cin), "cbbcbc");
    t1.Update(Rectangle(std::cin), "cbbd");
    t1.Update(Rectangle(std::cin), "cbbcbbc");
    t1.Update(Rectangle(std::cin), "cbbcbbcb");
    std::cout << t1.getItem("cbbcbbcb");
    std::cout << t1.getItem("cbbbbbcbcbcbcccbcc");
    std::cout << t1;
    TNaryTree<Rectangle> t3(t1);

    t3.Update(Rectangle(std::cin));
    t3.Update(Rectangle(std::cin), "cbbcbbcbb");
    t3.Update(Rectangle(std::cin), "cbbcc");

    std::cout << t1 << t3;

    t1.RemoveSubTree("ccc");
    t1.RemoveSubTree("b");
    t1.RemoveSubTree("ccbcbb");
    std::cout << t1;
    t1.RemoveSubTree("cb");
    std::cout << t1;
    t1.RemoveSubTree("cbb");
    std::cout << t1;
    t1.RemoveSubTree("cb");
    std::cout << t1;
    t1.RemoveSubTree("cbbcb");
    std::cout << t1;
    t1.RemoveSubTree("ccb");
    std::cout << t1;
    t1.RemoveSubTree();
    std::cout << t1 << t3;
    TNaryTree<Trapezoid> t2(7);
    t2.Update(Trapezoid(std::cin));
    t2.Update(Trapezoid(std::cin), "c");
    t2.Update(Trapezoid(std::cin), "cb");
    std::cout << t2;
    t2.RemoveSubTree();
    TNaryTree<Rhombus> t4(19);
    t4.Update(Rhombus(std::cin));
    t4.Update(Rhombus(std::cin), "b");
    t4.Update(Rhombus(std::cin), "c");
    t4.Update(Rhombus(std::cin), "cb");
    t4.Update(Rhombus(std::cin), "cbb");
    t4.Update(Rhombus(std::cin), "cbbb");
    t4.Update(Rhombus(std::cin), "cbbbb");
    t4.Update(Rhombus(std::cin), "cbbbbb");
    t4.Update(Rhombus(std::cin), "cbbbbbb");
    t4.Update(Rhombus(std::cin), "cbbbbbbb");
    t4.Update(Rhombus(std::cin), "cbbbbbbbb");
    t4.Update(Rhombus(std::cin), "cbbbbbbbbb");
    t4.Update(Rhombus(std::cin), "cbbbbbbbbbc");
    t4.Update(Rhombus(std::cin), "cbbbbbbbbbcb");
    t4.Update(Rhombus(std::cin), "cbbbbbbbbbcbb");
    t4.Update(Rhombus(std::cin), "cbbbbbbbbbcc");
    t4.Update(Rhombus(std::cin), "cbbbbbbbbbccb");
    t4.Update(Rhombus(std::cin), "cbbbbbbbbbcccc");
    t4.Update(Rhombus(std::cin), "cbbbbbbbbbccc");
    t4.Update(Rhombus(std::cin), "cbbbbbbbbbcccc");
    t4.Update(Rhombus(std::cin), "cbbbbbbbbbccccb");
    std::cout << t4;
    t4.RemoveSubTree("cbbbbbbbbbc");
    std::cout << t4;
    t4.RemoveSubTree("cccbcbc");
    t4.RemoveSubTree("c");
    std::cout << t4;
    t4.RemoveSubTree("");
    std::cout << t4;
    system("pause");
    return 0;
}
