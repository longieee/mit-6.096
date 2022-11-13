#include <iostream>
const int WIDTH = 3;
const int LENGTH = 3;

void transpose(const int input[][LENGTH], int output[][WIDTH]);
void printMat(int mat[LENGTH][WIDTH]);

int main()
{
    int mat[WIDTH][LENGTH] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int mat_t[LENGTH][WIDTH];
    transpose(mat, mat_t);
    std::cout << "Transposed Matrix: " << std::endl;
    printMat(mat_t);
    return 0;
}

void transpose(const int input[][LENGTH], int output[][WIDTH])
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            output[j][i] = input[i][j];
        }
    }
}
void printMat(int mat[LENGTH][WIDTH])
{
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}