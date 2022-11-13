#include <iostream>

int main()
{
    char *s = new char[100];
    int len = 0;
    std::cout << "Input string: ";
    std::cin.getline(s, 100);

    while (*(s + len) != '\0')
    {
        len++;
    }
    std::cout << "String: " << s << std::endl;
    std::cout << "String length: " << len << std::endl;
    return 0;
}