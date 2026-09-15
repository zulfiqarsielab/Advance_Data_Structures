#include <stdio.h>

#define OK 0
#define ERROR -1
#define ZERO_DETERMINANT -2

/* 1. Matrix transpose ------- Task 4*/

/* Function to calculate transpose of matrix */

int transposeMatrix(int a[][3], int transpose[][3])
{
    int i, j;

    if (a == NULL || transpose == NULL)
        return ERROR;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transpose[j][i] = a[i][j];
        }
    }

    return OK;
}

/* Function to print the output matrix after transpose */

void printTransposeMatrix(int matrix[][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", matrix[i][j]);
        }

        printf("\n");
    }
}

/* Now Main Function */

int main()
{
    int a[3][3];
    int transpose[3][3];
    int i, j;
    int status;

    /* Input Matrix a */

    printf("Enter matrix a of 3x3 size:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    /* Result of matrix transpose function */

    status = transposeMatrix(a, transpose);

    printf("\n. Matrix Transpose\n");

    if (status == OK)
    {
        printTransposeMatrix(transpose);
    }
    else
    {
        printf("Error: %d\n", status);
    }

    return 0;
}