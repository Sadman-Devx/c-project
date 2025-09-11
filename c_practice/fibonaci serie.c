#include<stdio.h>
int main()
{
    int n1=0,n2=1,count=0;
    int fibo,n;
    scanf("%d",&n);
    while(count<n){
        if(count<=1){
            fibo=count;
        }
        else{
            fibo = n1+n2;
            n1 = n2;
            n2 = fibo;
        }
        printf("%d ",fibo);
        count++;
    }




}
