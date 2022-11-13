#include <iostream>

int main()
{
    char *oddOrEven = "Never odd or even";
    // Create a pointer to a char value named nthCharPtr pointing to the 6th character of oddOrEven
    // (remember that the first item has index 0). Use the indexing operator.
    char *nthCharPtr = &oddOrEven[5];
    std::cout << "6th character address: " << &nthCharPtr << std::endl;
    std::cout << "6th character: " << *nthCharPtr << std::endl;

    // Using pointer arithmetic, update nthCharPtr to point to the 4th character in oddOrEven
    nthCharPtr = oddOrEven + 3;
    std::cout << "4th character address: " << &nthCharPtr << std::endl;
    std::cout << "4th character: " << *nthCharPtr << std::endl;

    char **pointerPtr = &nthCharPtr;
    std::cout << "Value stored in pointerPtr: " << pointerPtr << std::endl;
    std::cout << "Value pointed to by nthCharPtr: " << **pointerPtr << std::endl;

    // Update nthCharPtr to point to the next character in oddOrEven (i.e. one character past the location it currently points to)
    nthCharPtr++;
    std::cout << "&nthCharPtr: " << &nthCharPtr << std::endl;
    std::cout << "*nthCharPtr: " << *nthCharPtr << std::endl;

    // Using pointer arithmetic, print out how far away from the character currently pointed to by nthCharPtr is from the start of the string.
    std::cout << "How far away from the character currently pointed to by nthCharPtr is from the start of the string: " << nthCharPtr - oddOrEven << std::endl;

    return 0;
}