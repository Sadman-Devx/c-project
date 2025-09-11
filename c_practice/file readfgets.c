
#include<stdio.h>
int main()
{
    FILE *file;
    char ch[40];
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
            fgets(ch,25,file);
            printf("%s",ch);
        }
        fclose(file);
    }
    getch ();
}

