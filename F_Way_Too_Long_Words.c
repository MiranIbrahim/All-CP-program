#include <stdio.h>
#include <string.h>
int main()
{

    int n;
    scanf("%d ", &n);
    while (n--)
    {
        char s[101];
        scanf("%s", &s);
        int len = strlen(s);

        if (len > 10)
        {
            printf("%c%d%c", s[0], len-2, s[len - 1]);
            printf("\n");
        }
        else
        {
            printf("%s", s);
            printf("\n");
        }
    }
    return 0;
}