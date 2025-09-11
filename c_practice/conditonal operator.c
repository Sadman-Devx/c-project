#include<stdio.h>
int main()
{
    int a, b, large;
    scanf("%d %d", &a, &b);
    large = (a>b) ? a :b;
    printf("large number is = %d\n",large);
}
/*#include <stdio.h>

int main()
{
    int a,b,c,large;
    scanf("%d %d %d",&a, &b, &c);
    large=(a>b)?a:b;
    if (c>a && c>b)
    {
        printf("%d is a large number",c);
    }


    else{
    printf("%d is a large number",large);
    } return 0;
}*/
