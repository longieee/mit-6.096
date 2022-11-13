#include <iostream>

using namespace std;

int main()
{
    int arg1;
    arg1 = -1;
    {
        char arg1 = 'A';
        cout << arg1 << "\n";
        // Programm compiles, output 'A'
    }
    cout << arg1 << endl; // Output -1
    return 0;
}
