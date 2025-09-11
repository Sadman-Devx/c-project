#include<stdio.h>
int main()
{
    FILE *file;
    char name[30];
    int age;
    file = fopen("test.txt","a");

    if(file==NULL)
    {
        printf("file doesn't exist\n");
    }
    else
    {
        printf("file is opened\n");
        printf("enter your name:");
        gets(name);
        printf("enter your age:");
        scanf("%d",&age);

        //fprint(file pointer,format sapecifaction,variable)
        fprintf(file,"Name = %s,age = %d\n",name,age);

        printf("file is written successfully\n");

        fclose(file);
    }


}
