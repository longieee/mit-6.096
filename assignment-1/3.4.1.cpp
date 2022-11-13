#include <iostream>

int main()
{
    int n, out;

    while (true)
    {
        std::cout << "Input integer N: ";
        std::cin >> n;
        // output N/5 if N is nonnegative and divisible by 5, and -1 otherwise
        (n >= 0 && n % 5 == 0) ? out = n / 5 : out = -1;
        std::cout << out << std::endl;
    }
}