#include<stdio.h>
int main()
{
    int row,n,col;
    scanf(" %d",&n);

    for(row=1;row<=n;row++)
    {
        for(col=1;col<=row;col++)
        {
            printf(" %d",row%2);
        }
        printf("\n");
    }
}
