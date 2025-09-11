#include<stdio.h>
int main()
{
    FILE *file;
    char name[20];
    int age,pn,n;
    file = fopen("student.txt","a");

    if(file==NULL)
    {
        printf("file doesn't exist");
    }
    else
    {
        printf("file is opened\n");

        printf("Enter number of student: ");
        scanf("%d",&n);

        for(int i=0;i<n;i++)
        {
            printf("Enter a student name: ");
            scanf("%s",&name);

            printf("Enter a student age: ");
            scanf("%d",&age);

            printf("Enter a student phone number: ");
            scanf("%d",&pn);

            printf("\n");

            fprintf(file, "\n%-20s %5d %15d", name, age, pn);

        }

        fclose(file);
    }
}
