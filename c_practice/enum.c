#include<stdio.h>

enum days_of_week
{
    sun,mon,tue,wed,thu,fri,sat
};
int main()
{
    enum days_of_week day1,day2;
    day1 = tue;
    day2 = sat;
    printf("day 1 = %d\n",day1);
    printf("day 2 = %d\n",day2);
}
