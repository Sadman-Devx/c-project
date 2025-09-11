#include<stdio.h>
 struct person
 {
    int age;
    float salary;
 };
int main()
{    struct person person1 = {11,576.35}, person2 = {20,6732.89};

    if(person1.age==person2.age && person1.salary==person2.salary)
        printf("person1 equal person2");
    else
        printf("person1 are not equal person2");
}
