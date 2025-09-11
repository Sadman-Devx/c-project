
#include <stdio.h>

int main()
{
    int arr[] = {12,67,90,2,42,56,21,90,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i =0; i<size-1; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    int mid,l=0,h=size-1;
    int found =-1;
    int search = 42;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(search = arr[mid])
        {
            printf("\nelement is found at index no %d",mid);
            found = 1;
            break;
        }
        else if(search>arr[mid])
        {
            l = mid+1;
        }
        else
        {
            h = mid-1;
        }
    }
    if(!found)
    {
        printf("element is not found");
    }

    return 0;
}
