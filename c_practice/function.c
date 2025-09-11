/*
#include<stdio.h>
void traingle(double a,double b)
{
    printf("traingle is %.1lf\n",.5*a*b);
}
int main()
{

    traingle(8,9);
    traingle(5,7);
}

*/
#include<stdio.h>
double trianglearea(double a,double b);
int main(){

    double a,b;
    printf("enter a two number: ");
    scanf("%lf %lf", &a, &b);
    double area = trianglearea(a,b);
    printf("area = %.1lf",area);

}
double trianglearea(double a,double b)
{
    return .5 * a * b;
}
