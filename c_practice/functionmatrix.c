/*
#include<stdio.h>
void maximumvalue(int s1[])
{
    int maximum = s1[0];
    for(int i=0;i<6;i++)
    {
        if(maximum<s1[i])
        {
            maximum = s1[i];
        }
    }
    printf("the macimum vaue is %d",maximum);
}
int main()
{
    int s1[] = {13,57,4,23,9,121};

    maximumvalue(s1);
}
*/
#include<stdio.h>
int main()
{
    int result = fact(5);
    printf("factorial 5 is = %d",result);
}

int fact(int n)
{
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}

