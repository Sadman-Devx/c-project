#include<stdio.h>

struct person
{
    char name[50];
    int age;
    float salary;
};

int main()
{
 struct person person[4];
 int i;

 for(i=0;i<4;i++)
 {
     printf("Enter a information for person %d\n",i+1);
     printf("Enter a name:");
     fflush(stdin);
     gets(person[i].name);
     printf("enter a age:");
     scanf("%d",&person[i].age);
     printf("Enter a salary:");
     scanf("%f",&person[i].salary);
 }
 for(i=0;i<4;i++)
 {
     printf("Information for person %d\n",i+1);
     printf("name: %s\n",person[i].name);
     printf("age: %d\n",person[i].age);
     printf("salary: %f\n",person[i].salary);

 }
}
