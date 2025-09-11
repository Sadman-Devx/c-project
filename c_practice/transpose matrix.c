#include<stdio.h>
int main()
{
    int A[10][10],Transpose[10][10],row,col,i,j;
    printf("Enter a A matrix  row and colum: ");
    scanf("%d %d",&row,&col);
    //input a matrix
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("A [%d][%d] = ",i,j);
            scanf("%d",&A[i][j]);
        }

    }

    //printing a matrix
    printf("A =\n");

    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",A[i][j]);

        }
        printf("\n");

    }
    //transpose
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            Transpose[j][i]=A[i][j];

        }
    }
    //printing transpose
    printf("transpose \n");
    for(i=0;i<col;i++)
    {
        for(j=0;j<row;j++)
        {
            printf("%d ",Transpose[i][j]);

        }
        printf("\n");
    }
}
