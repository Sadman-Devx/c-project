#include<stdio.h>
int main()
{
    int number,start,end,count=0,totalofprimenumber=0,
                         sumofprimenumber=0;
    printf("Enter a starting number: ");
    scanf("%d",&start);
    printf("Enter a ending number: ");
    scanf("%d",&end);
    for(number=start; number<=end; number++)
    {
        count=0;
        if(number<=1)
        {
            count++;

        }
        else
        {
            for(int i=2; i<=number/2; i++)
            {
                if(number%i==0)
                {
                    count++;
                    break;
                }
            }
        }
        if(count==0)
        {
            printf("%d ",number);
            totalofprimenumber++;
            sumofprimenumber=sumofprimenumber+number;
        }
    }
    printf("\nTotal prime number %d\n",totalofprimenumber);
    printf("Sum of prime number %d\n",sumofprimenumber);
}
