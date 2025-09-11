#include<stdio.h>
#include<ctype.h>
int main()
{
    int number,sum=0,temp,remainder;
    printf("enter a number: ");
    scanf("%d",&number);
    temp=number;
    while(temp!=0)
    {
        remainder = temp%10;
        sum = sum+remainder;
        temp = temp/10;
    }
    printf("sum of digit %d\n",sum);
}
