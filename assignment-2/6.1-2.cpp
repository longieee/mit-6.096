#include <iostream>

/*
    The array decays to a pointer when passed.
    So sizeof only works to find the length of the array if you apply it to the original array.
*/
void printArray(int arr[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        std::cout << arr[i];
        if (i != arr_length - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

void printReverseArray(int arr[], int arr_length)
{
    for (int i = arr_length - 1; i >= 0; i--)
    {
        std::cout << arr[i];
        if (i != 0)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {3, 8, 4, 6, 3, 2, 9, 4, 234, 546, 2435, 652};

    int arr_length = sizeof(arr) / sizeof(int);
    std::cout << "Array: " << std::endl;
    printArray(arr, arr_length);
    std::cout << "Reversed Array: " << std::endl;
    printReverseArray(arr, arr_length);
    return 0;
}