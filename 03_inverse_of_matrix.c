#include <stdio.h>

#define OK 0
#define ERROR -1
#define ZERO_DETERMINANT -2

/* 1. Matrix inverse ------- Task 3*/

/* Function to calculate determinant of a 3x3 matrix */

int determinantMatrix(int a[][3], int *det)
{
    if (a == NULL || det == NULL)
        return ERROR;

    *det = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
         - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
         + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

    return OK;
}

/* Function to calculate inverse of matrix */

int inverseMatrix(int a[][3], float inverse[][3])
{
    int det;
    int i, j;

    if (a == NULL || inverse == NULL)
        return ERROR;

    determinantMatrix(a, &det);

    if (det == 0)
        return ZERO_DETERMINANT;

    /* Calculate inverse using adjoint / determinant */

    inverse[0][0] =  (float)(a[1][1] * a[2][2] - a[1][2] * a[2][1]) / det;
    inverse[0][1] = -(float)(a[0][1] * a[2][2] - a[0][2] * a[2][1]) / det;
    inverse[0][2] =  (float)(a[0][1] * a[1][2] - a[0][2] * a[1][1]) / det;

    inverse[1][0] = -(float)(a[1][0] * a[2][2] - a[1][2] * a[2][0]) / det;
    inverse[1][1] =  (float)(a[0][0] * a[2][2] - a[0][2] * a[2][0]) / det;
    inverse[1][2] = -(float)(a[0][0] * a[1][2] - a[0][2] * a[1][0]) / det;

    inverse[2][0] =  (float)(a[1][0] * a[2][1] - a[1][1] * a[2][0]) / det;
    inverse[2][1] = -(float)(a[0][0] * a[2][1] - a[0][1] * a[2][0]) / det;
    inverse[2][2] =  (float)(a[0][0] * a[1][1] - a[0][1] * a[1][0]) / det;

    return OK;
}

/* Function to print the output matrix after inverse */

void printInverseMatrix(float matrix[][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }

        printf("\n");
    }
}

/* Now Main Function */

int main()
{
    int a[3][3];
    float inverse[3][3];
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

    /* Result of matrix inverse function */

    status = inverseMatrix(a, inverse);

    printf("\n. Matrix Inverse\n");

    if (status == OK)
    {
        printInverseMatrix(inverse);
    }
    else if (status == ZERO_DETERMINANT)
    {
        printf("Error: Matrix has no inverse because determinant is zero.\n");
    }
    else
    {
        printf("Error: %d\n", status);
    }

    return 0;
}