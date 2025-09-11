#include<stdio.h>
int main()
{
    char ch;
    scanf("%c", &ch);
    if (ch>='a' && ch<='z')
    {
        printf("small");
    }
    else if (ch>='A' && ch<='Z')
    {
        printf("large");
    }
    else
    {
        printf("not a letter");
    }
    getch();
}
