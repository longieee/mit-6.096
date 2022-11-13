#include <iostream>

int main()
{
    int n;

    while (true)
    {
        std::cout << "Input integer N: ";
        std::cin >> n;
        // output N/5 if N is nonnegative and divisible by 5, and -1 otherwise
        if (n >= 0 && n % 5 == 0)
        {
            std::cout << n / 5 << std::endl;
        }
        else if (n == -1)
        {
            std::cout << "Goodbye." << std::endl;
            break;
        }
        else
        {
            continue;
        }
    }

    return 0;
}