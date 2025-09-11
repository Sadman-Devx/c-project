#include<stdio.h>
#include<string.h>
int main()
{
    FILE *file;
    char name[30] = "shadman shakib";
    int lentgh = strlen(name);
    file = fopen("test.txt","w");

    if(file==NULL)
    {
        printf("file doesn't exist\n");
    }
    else
    {
        printf("file is opened\n");
        for(int i = 0;i<lentgh;i++)
        {
            fputc(name[i],file);
        }
        printf("file is written successfully\n");

        fclose(file);
    }
    getch ();
}

