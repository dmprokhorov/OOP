#include "rectangle.h"
#include "trapezoid.h"
#include "rhombus.h"
int main()
{
    Rectangle rec1(std::cin);
    rec1.Print(std::cout);
    std::cout << rec1.VertexesNumber() << std::endl;
    std::cout << rec1.Square() << std::endl;

    Trapezoid t1(std::cin);
    t1.Print(std::cout);
    std::cout << t1.VertexesNumber() << std::endl;
    std::cout << t1.Square() << std::endl;

    Rhombus r1(std::cin);
    r1.Print(std::cout);
    std::cout << r1.VertexesNumber() << std::endl;
    std::cout << r1.Square() << std::endl;

    Figure* rec2 = new Rectangle(std::cin);
    rec2->Print(std::cout);
    std::cout << rec2->VertexesNumber() << std::endl;
    std::cout << rec2->Square() << std::endl;
    delete rec2;

    Figure* t2 = new Trapezoid(std::cin);
    t2->Print(std::cout);
    std::cout << t2->VertexesNumber() << std::endl;
    std::cout << t2->Square() << std::endl;
    delete t2;

    Figure* r2 = new Rhombus(std::cin);
    r2->Print(std::cout);
    std::cout << r2->VertexesNumber() << std::endl;
    std::cout << r2->Square() << std::endl;
    delete r2;

    system("pause");
    return 0;
}
