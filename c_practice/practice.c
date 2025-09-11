#include<stdio.h>
int main()
{
    int start,end,remainder,tem,i,num,sum;
    printf("enter a starting number: ");
    scanf("%d",&start);
    printf("enter a ending number: ");
    scanf("%d",&end);
    for(num=start;num<=end;num++)
    {
        tem=num;
       while(tem!=0)
    {
        remainder = tem%10;
        sum = sum*10+remainder;
        tem = tem/10;
    }
    if(num==sum)
    {
        printf("%d");
    }
    }



    return 0;
}
