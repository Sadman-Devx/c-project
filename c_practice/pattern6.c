#include<stdio.h>
int main()
{
    int n,row,col;
    scanf("%d",&n);
    for(row=1;row<=n;row++)
    {
        for(col=1;col<=row;col++)
        {
            printf("%d ",col*row);
        }
        printf("\n");
    }
}
/*// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
int n,row,col;
scanf("%d",&n);
for(row=1;row<=n;row++)
{
    for(col=1;col<=n-row;col++)
    {
        printf(" ");
    }
    for(col=1;col<=2*row-1;col++)
    {printf("*");}
    printf("\n");
}


    return 0;
}
*/

/*// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
int n,row,col;
scanf("%d",&n);
for(row=n;row>=1;row--)
{
    for(col=1;col<=n-row;col++)
    {
        printf(" ");
    }
    for(col=1;col<=2*row-1;col++)
    {printf("*");}
    printf("\n");
}


    return 0;
}
*/
