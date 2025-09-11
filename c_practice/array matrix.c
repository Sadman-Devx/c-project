#include<stdio.h>
int main()
{
    int A[3][2];
    int B[3][2];
    int C[3][2];
    //input A matrix
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<2;col++)
        {
            printf("A [%d] [%d] = ",row,col);
            scanf("%d",&A[row][col]);
        }

    }
    //print A matrix
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<2;col++)
        {

            printf("%d ",A[row][col]);
        }
        printf("\n");
    }
    //input B matrix
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<2;col++)
        {
            printf("B [%d] [%d] = ",row,col);
            scanf("%d",&B[row][col]);
        }

    }
    //print B matrix
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<2;col++)
        {

            printf("%d ",B[row][col]);
        }
        printf("\n");
    }
    //print C matrix
    printf("c = \n1");
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<2;col++)

        {

            printf("%d ",A[row][col] + B[row][col]);
        }
        printf("\n");
    }

}
