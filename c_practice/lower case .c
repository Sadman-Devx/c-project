#include<stdio.h>
int main()
{
    char lower, upper;
    printf("enter a lower character : ");
    scanf("%c",&lower);
    upper = lower-32;
    printf("enter a upper character %c\n",upper);
    /* or printf("enter a upper character %c\n",lower-32)
    upper = toupper(lower)*/
}
