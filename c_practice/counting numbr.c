#include<stdio.h>
int main()
{
    int number,count=0;
    scanf("%d",&number);
    while(number !=0)
    {
        number = number/10;
        ++count;
    }
    printf("totat number of digit: %d\n",count);
}
