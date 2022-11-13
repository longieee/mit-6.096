#include <iostream>

using namespace std;
int main()
{
    int number;
    cout << " Enter a number : ";
    cin >> number;
    if (number < 0)
    {
        cout << "Invalid Input" << endl;
    }
    else
    {
        cout << "The factorial of " << number << " is ";
        unsigned long long int accumulator = 1;
        for (; number > 0; accumulator *= (unsigned long long int)number--)
            ;
        cout << accumulator << "\n";
    }
    return 0;
}