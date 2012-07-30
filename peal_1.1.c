#include <stdio.h>

#define MAX 10000000
#define BIT 32
#define SHIFT 5           
#define MASK 0x1F

int a[1+MAX/BIT];

void set(int n)     //set the bit map 
{
    /*int t;
    t=n%BIT;
    a[n/BIT]=a[n/BIT]|(1<<t);*/
    a[n>>SHIFT]=a[n>>SHIFT]|(1<<(n&MASK));     //n>>SHIFT == n/BIT n&MASK == n%MASK;together we get the position n to 1
}                                               

void clear(int n) // clear the bit map
{
    a[n>>SHIFT]=a[n>>SHIFT]&(~(1<<(n&MASK)));   //set position n to 0; 
}

int test(int n)
{
    return a[n>>SHIFT] & (1<<(n&MASK));        //probe positions setted to 1; 
}

int main(int argc, char *argv[])
{
    int i,n;
    for(i=1;i<=MAX;i++)
    {
        clear(i);
    }    
    while(scanf("%d",&n)!=EOF)
    {
        set(n);
    }
    for(i=1;i<=MAX;i++)
    {
        if(test(i))
            printf("%d ",i);
    }
    return 0;
}
