#include<stdio.h>
int main()
{
    char ch;
    scanf("%c", &ch);
    switch(ch)
    {

    case 'a':
    case 'i':
    case 'o':
    case 'u':
    case 'e':
    case 'A':
        printf("vowel\n");
        break;
    default :
        printf("constant\n");
    }
}
