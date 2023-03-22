
#include <stdio.h>
#include<stdbool.h>
#define N 3

int board[N][N];

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int row, int col)
{
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Function to solve N-Queens problem using backtracking
bool solveNQueensUtil(int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 1;

            if (solveNQueensUtil(col + 1))
                return true;

            board[i][col] = 0; // backtrack
        }
    }

    return false;
}

// Function to solve N-Queens problem
void solveNQueens()
{
    if (solveNQueensUtil(0) == false)
    {
        printf("Solution does not exist");
        return;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int main()
{
    printf("solution for N= %d\n",N);
    solveNQueens();
    return 0;
}
