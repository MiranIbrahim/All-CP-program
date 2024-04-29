#include <stdio.h>
#include <string.h>
int main()
{

    char a[21], b[21];
    scanf("%s %s", a, b);

    int i = 0;
    while (1)
    {
        if (a[i] == '\0' && b[i] == '\0')
        {
            printf("%s\n", a);
            break;
        }
        else if (a[i] == '\0')
        {
            printf("%s\n", a);
            break;
        }
        else if (b[i] == '\0')
        {
            printf("%s\n", b);
            break;
        }
        else if (a[i] != b[i])
        {
            if (a[i] < b[i])
            {
                printf("%s\n", a);
            }
            else
            {
                printf("%s\n", b);
            }
            break;
        }
        else if (a[i] == b[i])
        {
            i++;
        }
    }
    return 0;
}