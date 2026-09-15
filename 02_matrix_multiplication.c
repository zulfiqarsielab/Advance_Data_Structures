#include <stdio.h>

#define OK 0
#define ERROR -1
#define ZERO_DETERMINANT -2

/* 1. Matrix multiplication ------- Task 2*/

int multiplyMatrix(int a[][3], int b[][3], int c[][3])
{
    int i, j, k;

    if (a == NULL || b == NULL || c == NULL)
        return ERROR;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            c[i][j] = 0;

            for (k = 0; k < 3; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    return OK;
}

/* Function to print the output matrix after multiplication */

void printMultiplyMatrix(int matrix[][3])
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
    int b[3][3];
    int result[3][3];
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

    /* Input Matrix b */

    printf("Enter matrix b of 3x3 size:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    /* Result of matrix multiplication function */

    status = multiplyMatrix(a, b, result);

    printf("\n. Matrix Multiplication\n");

    if (status == OK)
    {
        printMultiplyMatrix(result);
    }
    else
    {
        printf("Error: %d\n", status);
    }

    return 0;
}