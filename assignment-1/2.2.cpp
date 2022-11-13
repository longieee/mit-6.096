#include <iostream>

int main()
{
    const char *s = "Hello, World!";
    int n;
    std::cout << "Input n, number of times to print: ";
    std::cin >> n;

    std::cout << "For loop:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << s << std::endl;
    }

    std::cout << "While loop:" << std::endl;
    int n_while = n;
    while (n_while > 0)
    {
        std::cout << s << std::endl;
        n_while--;
    }

    std::cout << "Do...While loop:" << std::endl;
    int n_do_while = n;
    do
    {
        std::cout << s << std::endl;
        n_do_while--;
    } while (n_do_while > 0);

    return 0;
}