#include<stdio.h>
void calculatepower(double a, double b)
{
    double result = 1,i;
    for(i=1;i<=b;i++)
    {
        result = result*a;
    }
    printf("%.1lf\n",result);
}
int main()
{
    double base,exp;
    printf("Enter a base: ");
    scanf("%lf",&base);
    printf("Enter a exp: ");
    scanf("%lf",&exp);
    calculatepower(base,exp);

}
