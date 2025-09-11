/*#include<stdio.h>//string copy
int main()
{
    char source[] = "C Programing";
    char target[20];
    strcpy(target,source);
    printf(" target is %s\n",target);

}
*/
/*
#include<stdio.h>//string connect
#include<string.h>
int main()
{
    char source[] = "C Programing";
    char target[] = "is the mother of languge";
    strcat(source,target);
    printf("%s\n",source);

}
*/
/*
#include<stdio.h>
int main()
{
    char str1[50] = "my name is ";
    char str2[] = "shadman shakib";
    int i=0,len=0,j=0;
    while(str1[i]!='\0')
   {
       i++;
       len++;
   }
   while(str2[j]!='\0')
   {
       str1[len+j] = str2[j];
       j++;
   }
   printf("str1 = %s",str1);
}
*/
//compare
/*#include <stdio.h>
#include <string.h> // Include string.h for strcmp

int main()
{
    char str1[] = "shadman";
    char str2[] = "shakib";

    int d = strcmp(str1, str2);  // Compare str1 and str2

    if (d == 0)
    {
        printf("The strings are equal.\n");
    }
    else
    {
        printf("The strings are not equal.\n");
    }

    return 0;
}
*/
/*
#include<stdio.h>
#include <string.h>//reverse
int main()
{
    char name[] = "shadman shakib";
    printf("%s\n",name);
    strrev(name);
    printf("%s\n",name);
}
*/
/*
#include<stdio.h>
#include<string.h>//reverse without function and pailondrome
int main()
{
    char str1[30] = "shakib al hasan";
    char str2[30] ;
    int i=0,len=0,j;
    while(str1[i]!='\0'){
        i++;
        len++;
    }
    for(j=0,i=len-1;i>=0;i--,j++)
    {
        str2[j]=str1[i];
    }
    str2[j]='\0';
    printf("%s\n",str1);
    printf("%s\n",str2);
    int d = strcmp(str1,str2);
    if(d==0)
    {
        printf("string is palindrom\n");
    }
    else
    {
        printf("string is not palindrome\n");
    }
}
*/
/*
#include<stdio.h>
#include<string.h>
int main()
{
    char str1[20] = "suji";
    char str2[20] = "princes";
    char temp[20] ;
    printf("before swapping\n");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);

    strcpy(temp,str1);
    strcpy(str1,str2);
    strcpy(str2,temp);
    printf("after swapping\n");
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
}
*/
/*
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],ch;
    printf("Enter a string:");
    gets(str);
    int i,vowel,constant,digit,word,other;
    i=vowel=constant=digit=word=other=0;
    while((ch=str[i])!='\0')
    {
        if(ch=='a' || ch=='i' || ch=='u' || ch=='e' || ch=='o' ||
           ch=='A' || ch=='I' || ch=='U' || ch=='E' || ch=='O')
        vowel++;
        else if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        constant++;
        else if(ch>='0' && ch<='9')
            digit++;
        else if(ch==' ')
            word++;
        else
            other++;

        i++;

    }
    word++;
    printf("number of vowel: %d\n",vowel);
    printf("number of constant: %d\n",constant);
    printf("number of digit: %d\n",digit);
    printf("number of word: %d\n",word);
    printf("number of other: %d\n",other);
}
*/

#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("Enter a string:");
    gets(str);
    int i,small,capital,digit;
    i=small=capital=digit=0;
    while(str[i]!='\0')
    {
        if(str[i]>=65 && str[i]<=90)
            capital++;
        else if(str[i]>=97 && str[i]<=122)
            small++;
        else if(str[i]>=48 && str[i]<=57)
            digit++;
        i++;

    }

    printf("number of small: %d\n",small);
    printf("number of capital: %d\n",capital);
    printf("number of digit: %d\n",digit);

}
