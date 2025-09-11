#include<stdio.h>
int main()
{
    int n1,n2,sum=0,a=1,b=2;
    scanf("%d %d",&n1,&n2);
    printf("1.2 + 2.3 + 3.4 +....+ %d.%d",n1,n2);

    while(a<=n1 && b<=n2)
    {
        sum=sum+a*b;
        a=a+1;
        b=b+1;
    }
    printf("=%d\n",sum);
}
