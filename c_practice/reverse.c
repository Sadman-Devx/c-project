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
        sum = sum*10+remainder;
        temp = temp/10;
    }
    printf("reverse number %d\n",sum);
}

