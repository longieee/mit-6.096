#include <iostream>

void swap(int *x, int *y);

int main()
{
    int x = 10, y = 20;

    std::cout << "Before swap:\n"
              << "x: " << x << '\n'
              << "y: " << y << std::endl;
    swap(&x, &y);
    std::cout << "After swap:\n"
              << "x: " << x << '\n'
              << "y: " << y << std::endl;
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}