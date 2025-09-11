#include<stdio.h>
struct person
{
    char name[50];
    int age;
    float salary;
};
void display(struct person p)
{
    printf("\nName: %s\n",p.name);
    printf("age: %d\n",p.age);
    printf("salary: %.2f\n",p.salary);
}
int main()
{
    struct person person1,person2;
    strcpy(person1.name,"shadman hasan");
    person1.age = 27;
    person1.salary = 756.95;
    display(person1);

    strcpy(person2.name,"shadman shakib");
    person2.age = 25;
    person2.salary = 856.95;
    display(person2);

}
