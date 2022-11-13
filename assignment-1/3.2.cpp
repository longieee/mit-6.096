#include <iostream>

int main()
{
    int n, max, min, range;
    int sum = 0;
    double mean;
    std::cout << "input N: ";
    std::cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        sum += arr[i];
        if (i == 0)
        {
            max = arr[0];
            min = arr[0];
        }

        if (max < arr[i])
        {
            max = arr[i];
        }
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    mean = (double)sum / n;
    range = max - min;
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "Range: " << range << std::endl;
}