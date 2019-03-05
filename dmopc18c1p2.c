#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int k;
    scanf("%d %d", &n, &k);
    
    int* p = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        if ((p[i]-i-1)%k != 0)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    
    return 0;
}