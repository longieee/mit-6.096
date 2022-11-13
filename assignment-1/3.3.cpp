#include <iostream>

int main()
{
    int n, count = 0, start = 3, current = 3;
    bool is_prime;
    std::cout << "Input N: ";
    std::cin >> n;

    if (n == 1)
    {
        std::cout << 2 << std::endl;
        return 0;
    }
    else
    {
        std::cout << 2 << std::endl;
        while (true)
        {
            is_prime = true;
            for (int i = 3; i < current; i += 2)
            {
                if (current % i == 0)
                {
                    is_prime = false;
                }
            }
            if (is_prime)
            {
                std::cout << current << std::endl;
                count++;
            }
            current += 2;
            if (count == n - 1)
            {
                break;
            }
        }
        return 0;
    }
}