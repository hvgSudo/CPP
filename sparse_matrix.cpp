#include <iostream>

int main()
{
    int i, j, k, size;
    int compactmatrix[3][size];
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] != 0)
                size++;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] != 0)
            {
                compactmatrix[0][k] = i;
                compactmatrix[1][j] = j;
                compactmatrix[2][k] = matrix[i][j];
                k++;
            }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size; j++)
            std::cout << compactmatrix[i][j];
        std::cout << "\n";
    }
    return 0;
}