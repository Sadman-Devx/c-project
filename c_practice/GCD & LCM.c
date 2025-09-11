#include<stdio.h>
int main()
{
    int num1,num2,n1,n2,rem,GCD,LCM;
    printf("enter a two number: ");
    scanf("%d %d",&num1, &num2);
    n1=num1;
    n2=num2;
    while(n2!=0)
    {
        rem = n1%n2;
        n1=n2;
        n2=rem;
    }
    GCD=n1;
    LCM=(num1*num2)/GCD;
    printf("GCD is a %d\n",GCD);
    printf("LCM is a %d\n",LCM);
}
