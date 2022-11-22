#include <iostream>
#include "geometry.h"

void printAttributes(Polygon *p);

int main()
{
    int llx, lly, urx, ury;
    int ax, ay, bx, by, cx, cy;
    std::cout << "Enter rectangle's lower left:" << std::endl;
    std::cin >> llx >> lly;
    std::cout << "Enter rectangle's upper right:" << std::endl;
    std::cin >> urx >> ury;

    Point ll(llx, lly), ur(urx, ury);
    Rectangle rectangle(ll, ur);

    std::cout << "Enter triangle's first point:" << std::endl;
    std::cin >> ax >> ay;
    std::cout << "Enter triangle's second point:" << std::endl;
    std::cin >> bx >> by;
    std::cout << "Enter triangle's third point:" << std::endl;
    std::cin >> cx >> cy;

    Point a(ax, ay), b(bx, by), c(cx, cy);
    Triangle triangle(a, b, c);

    std::cout << "Rectangle info:" << std::endl;
    printAttributes(&rectangle);
    std::cout << "Triangle info:" << std::endl;
    printAttributes(&triangle);

    return 0;
}

void printAttributes(Polygon *p)
{
    std::cout << "Area: " << p->area() << std::endl;
    std::cout << "Point details: " << std::endl;
    const PointArray *pa = p->getPoints();
    for (int i = 0; i < pa->getSize(); i++)
    {
        std::cout << '(' << pa->get(i)->getX() << ',' << pa->get(i)->getY() << ')' << std::endl;
    }
}