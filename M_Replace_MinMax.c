#include <stdio.h>

int main()
{

    int n, mxi, mni, min = 100000, max = -100000;
    scanf("%d", &n);
    int a[n + 1];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > max)
        {
            max = a[i];
            mxi = i;
        }

        if (a[i] < min)
        {
            min = a[i];
            mni = i;
        }
    }
    int temp = a[mxi];
    a[mxi] = a[mni];
    a[mni] = temp;
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}