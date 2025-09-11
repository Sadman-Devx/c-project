 #include<stdio.h>
void generatelucas(int numterms)
{
    int first=2,secod=1;
    printf("lucas series up to %d terms: \n",numterms);
    printf("%d %d",first,secod);

    for(int i=3; i<=numterms; i++)
    {
        int next = first + secod;
        printf(" %d",next);
        first = secod;
        secod = next;

    }
    printf("\n");
}
int main()
{
    int numterms;
    printf("enter the numterms of lucas series: ");
    scanf("%d",&numterms);
    generatelucas(numterms);
    return 0;
}
