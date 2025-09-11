// Online C compiler to run C program online
#include <stdio.h>
void modify(int *num)
{
    *num = 14;
}

int main() {
    int num=20;
    printf("before modification: %d\n",num);
    modify(&num);
    printf("after modification: %d\n ",num);

    return 0;
}
