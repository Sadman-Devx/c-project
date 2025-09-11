#include<stdio.h>
int main()
{
    int row,n,col;
    printf("enter N = ");
    scanf(" %d",&n);

    for(row=1;row<=n;row++)
    {
        for(col=1;col<=row;col++)
        {
            printf("%c ",row+64);//+96 cause small latter
            //printf("*")
        }
        printf("\n");
    }
}
