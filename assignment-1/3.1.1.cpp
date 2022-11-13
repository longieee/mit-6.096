#include <iostream>

using namespace std;

int main()
{
    int arg1;
    arg1 = -1;

    int x, y, z;
    char myDouble = '5';
    char arg1 = 'A';
    /*
        3.1.cpp:12:10: error: redefinition of 'arg1' with a different type: 'char' vs 'int'
            char arg1 = 'A';
                ^
        3.1.cpp:7:9: note: previous definition is here
            int arg1;
                ^
        1 error generated.
    */

    cout << arg1 << '\n';
    return 0;
}