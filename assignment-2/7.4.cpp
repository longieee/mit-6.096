#include <iostream>

void swap(int **x, int **y);

int main()
{
    int x = 10, y = 20;
    int *ptr1 = &x, *ptr2 = &y;

    std::cout << "Before swap:\n"
              << "x: " << *ptr1 << '\n'
              << "y: " << *ptr2 << std::endl;
    swap(&ptr1, &ptr2);
    std::cout << "After swap:\n"
              << "x: " << *ptr1 << '\n'
              << "y: " << *ptr2 << std::endl;
    return 0;
}

void swap(int **x, int **y)
{
    int *temp = *y;
    *y = *x;
    *x = temp;
}