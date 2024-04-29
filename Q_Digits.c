#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a;
        scanf("%d", &a);
        do
        {

            int rem = a % 10;
            a = a / 10;
            printf("%d ", rem);

        } while (a != 0);
        printf("\n");
    }
    return 0;
}