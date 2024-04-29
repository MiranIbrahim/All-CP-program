#include <stdio.h>

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n];
    int sum[m + 1];
    for (int i = 0; i <= m; i++)
    {
        sum[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum[arr[i]]++;
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", sum[i]);
    }
    return 0;
}