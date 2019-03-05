#include <stdio.h>
#define inf 0x3f3f3f3f

int main()
{
    unsigned int a, b;
    scanf("%x%x", &a, &b);
    
    if (a+b > inf) printf("Yes");
    else printf("No");
    
    return 0;
}