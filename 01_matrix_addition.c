#include <stdio.h>

#define OK 0
#define ERROR -1
#define ZERO_DETERMINANT -2

/*1. Matrix addition -------Task 1*/

int addMatrix(int a[][3], int b[][3], int c[][3])
{
    int i, j;

    if (a == NULL || b == NULL || c == NULL)
        return ERROR;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    return OK;
}

/*Function to print the output matrix after addition*/
void printAddMatrix(int matrix[][3])
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

/* Now Main Function*/
int main()
{
    int a[3][3];
    int b[3][3];
    int result[3][3];
    int i, j;
    int status;

    /*Input Matrix a*/
    printf("Enter matrix a of 3x3 size:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    /*Input Matrix b*/
    printf("Enter matrix b of 3x3 size:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    /*Result of matrix addition function*/
    status = addMatrix(a, b, result);

    printf("\n. Matrix Addition\n");

    if (status == OK)
    {
        printAddMatrix(result);
    }
    else
    {
        printf("Error: %d\n", status);
    }

    return 0;
}