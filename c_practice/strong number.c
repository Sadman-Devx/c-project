#include<stdio.h>
int main()
{
    int num,sum=0,rem,tem,i,fact;
    scanf("%d",&num);
    tem = num;
    while(tem!=0)
    {
        rem = tem % 10;
        fact=1;
        for(i=1;i<=rem;i++)
        {
            fact = fact*i;
        }
        sum = sum + rem;
        tem = tem/10;
    }
    if(num==sum)
    {
        printf("strong number",num);

    }
    else
    {
        printf("not strong number",num);
    }
}
