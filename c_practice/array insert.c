#include<stdio.h>
int main()
{
    int array[8],size,i,num,pos;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    printf("Enter the array: ");
    for(i = 0; i<size;i++){
        scanf("%d",&array[i]);
        }
        printf("the array is:\n");
        for(i=0;i<size;i++){
            printf("%d ",array[i]);
        }
        /*printf("\nEnter the number: ");
        scanf("%d",&num);*/
        printf("Enter the positon: ");
        scanf("%d",&pos);
        if(size>=array[8])
            printf("insert is not possible");
        else{
            for (i = pos - 1; i < size - 1; i++) {
        array[i] = array[i + 1];
    }

    // Decrease the size of the array
    size--;
            printf("insert the array:\n");
            for(i=0;i<size;i++){
                printf("%d ",array[i]);
            }
        }

}
