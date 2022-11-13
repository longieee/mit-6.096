#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

int main()
{
    double x, y;
    long double pi;
    unsigned long int n;
    int count = 0;
    std::cout << "Input n: ";
    std::cin >> n;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        x = rand() / (double)RAND_MAX;
        y = rand() / (double)RAND_MAX;
        if (sqrt(x * x + y * y) < 1)
        {
            // std::cout << "Dart throw: " << x << " - " << y << std::endl;
            count++;
        }
    }
    std::cout << "Total number of dart throws inside circle: " << count << std::endl;
    pi = count / static_cast<long double>(n) * 4;
    std::cout << "pi estimation: " << pi << std::endl;
    return 0;
}