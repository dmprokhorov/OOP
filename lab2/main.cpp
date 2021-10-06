﻿// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "tnarytree.h"
int main()
{
    double S = 0.;
    TNaryTree t1(3);
    std::cout << t1;
    t1.Update(Rectangle(std::cin), "cbc");
    t1.Update(Rectangle(std::cin), "");
    t1.Update(Rectangle(std::cin));
    t1.Update(Rectangle(std::cin), "c");
    t1.Update(Rectangle(std::cin), "cb");
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
    std::cout << t1;
    t1.Clear("ccc");
    t1.Clear("b");
    t1.Clear("ccbcbb");
    t1.Clear("cbb");
    std::cout << t1;
    t1.Clear("cbbcb");
    std::cout << t1;
    t1.Clear("ccb");
    std::cout << t1;
    t1.Clear();
    std::cout << t1;
    t1.Update(Rectangle(std::cin), "cbc");
    //t1.Update(Rectangle(std::cin));
    TNaryTree t2(7);
    t2.Update(Rectangle(std::cin));
    t2.Update(Rectangle(std::cin), "c");
    t2.Update(Rectangle(std::cin), "cb");
    t2.Clear();
    TNaryTree t3(t1);
    std::cout << t1 << t3;
    system("pause");
    return 0;
}

