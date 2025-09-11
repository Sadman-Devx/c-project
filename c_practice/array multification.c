#include<stdio.h>
int main()
{
    int first[10][10],second[10][10],r1,r2,c1,c2,i,j,k,result[10][10],sum=0;
    printf("Enter a first matrix rows and colum: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter a second matrix row and colum: ");
    scanf("%d %d",&r2,&c2);
    while(c1!=r2)
    {
        printf("Error\n");
        printf("Enter a first matrix rows and colum: ");
        scanf("%d %d",&r1,&c1);
        printf("Enter a second matrix row and colum: ");
        scanf("%d %d",&r2,&c2);
    }
    //input first matrix
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("A [%d] [%d] = ",i,j);
            scanf("%d",&first[i][j]);
        }
    }
    //input second matrix
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("B [%d] [%d] = ",i,j);
            scanf("%d",&second[i][j]);
        }
    }
    //printing frist matrix
    printf("A =\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d ",first[i][j]);
        }
        printf("\n");
    }
    //printing second matrix
    printf("B =\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d ",second[i][j]);
        }
        printf("\n");
    }
    //multification
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            for(k=0;k<c1;k++)
            {
                sum = sum + first[i][k]*second[k][j];
            }
            result[i][j] = sum;
            sum=0;
        }
    }
    //pinting result
     printf("result =\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }

}
