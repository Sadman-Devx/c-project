/*#include<stdio.h>
int main()
{
    int number[6],sum=0;
    float avg;
    for(int index=0;index<6;index++)
    {
        printf("enter number %d = ",index+1);
        scanf("%d",&number[index]);
    }
    for(int index=0;index<6;index++)
    {
        sum = sum + number[index];
    }
    printf("the sum is %d\n",sum);
    avg = sum/6.0;
    printf("avg = %.2f",avg);
}
*/
/*#include<stdio.h>
int main()
{
    int number[] = {13,65,443,67,45,-7};
    int maximum = number[0];
    int minimum = number[0];
    for(int index=1; index<6; index++)
    {
        if(maximum<number[index]){
            maximum = number[index];
        }
        if(minimum>number[index]);
        minimum = number[index];
    }
    printf("Maximum number is = %d\n",maximum);
    printf("Minimum number is = %d\n",minimum);
}
*/
/*#include<stdio.h>
int main()
{
    int number[] = {12,54,87,34,23,-54};
    int searchNumber = -54;
    int found = -2;
    for(int index=0; index<6; index++)
    {
        if(number[index]==searchNumber)
        {
            found = index;
            break;
        }
    }
    if(found == -1)
    {
        printf("%d is not found",searchNumber);
    }
    else
    {
        printf("%d is found in position %d",searchNumber,found);
    }
    return 0;

}
*/
/*
#include<stdio.h>
int main()
{
    int number[] = {13,43,45,3,98};
    int lengthOfArray = sizeof(number)/sizeof(number[0]);
    //printf("%d\n",lengthOfArray);
    if(lengthOfArray<2)
    {
        printf("array should hve at least two element\n");
    }
    int first,second;
    if(number[1]>number[0])
    {
        first = number[1];
        second = number[0];
    }
    else
    {
        first = number[0];
        second = number[1];
    }
    for(int index = 2; index<lengthOfArray; index++)
    {
        if(number[index]>first)
        {
            second = first;
            first = number[index];
        }
        else if(number[index]>second && number[index]!=first)
        {
            second = number[index];
        }

    }
    printf("first largest %d\n",first);
    printf("second largest %d\n",second);
}
*/
#include<stdio.h>
int main()
{
    int A[30],n;
    printf("how many fibonaci number : ");
    scanf("%d",&n);

    A[0] = 0;
    A[1] = 1;
    for(int i =2;i<n;i++)
    {
        A[i] = A[i-1]+A[i-2];


    }
    printf("\n");

    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

}

