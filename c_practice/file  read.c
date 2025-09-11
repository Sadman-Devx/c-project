#include<stdio.h>
int main()
{
    FILE *file;
    char ch;
    file = fopen("test.txt","r");

    if(file==NULL)
    {
        printf("file doesn't exist\n");
    }
    else
    {
        printf("file is opened\n");
        while(!feof(file))
        {
            ch = fgetc(file);
            printf("%c",ch);
        }
        fclose(file);
    }
    getch ();
}

