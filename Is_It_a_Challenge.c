#include <stdio.h>

int main()
{

    int n, p, q;
    scanf("%d", &n);
    if (n > 0)
    {
        p = 1;
        q = n;
    }
    else
    {
        p = n;
        q = 0;
    }
    for (int i = p; i <= q; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}