/*
#include<stdio.h>
int main()
{
    int x=5;
    int *ptr;
    ptr = &x;
    printf("%d\n",x);
    printf("%d\n",&x);
    printf("%d\n",ptr);
    printf("%d\n",*ptr);
    printf("%d\n",&ptr);


}
*/
/*
#include<stdio.h>
int main()
{
    int x = 5,sum;
    int y=18;
    int *ptr1;
    int *ptr2;
    ptr1=&x;
    ptr2=&y;
    sum = *ptr1 + *ptr2;
    printf("%d\n",sum);
}
*/
#include<stdio.h>
int main()
{
    int a[5]={2,8,9,5,4};
    int *ptr,i;
    ptr = &a[0];
    for(i=0;i<5;i++)
    {
        printf("%d\n",*ptr);
        *ptr++;
    }
}
