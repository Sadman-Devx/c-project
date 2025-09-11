#include<stdio.h>
#include<string.h>
int main()
{
    FILE *file;
    char name[30];
    int lentgh = strlen(name);
    file = fopen("test.txt","w");

    if(file==NULL)
    {
        printf("file doesn't exist\n");
    }
    else
    {
        printf("file is opened\n");
        printf("enter your name:");
        gets(name);
        fputs(name,file);
        printf("file is written successfully\n");

        fclose(file);
    }
    getch ();
}


