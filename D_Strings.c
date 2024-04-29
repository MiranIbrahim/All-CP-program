#include <stdio.h>
#include <string.h>
int main()
{

    char a[11], b[11];
    scanf("%s", &a);
    scanf("%s", &b);
    int lenA = strlen(a);
    int lenB = strlen(b);
    printf("%d %d\n", lenA, lenB);
    // ----------------2nd line logic------------------
    int len = lenA + lenB + 1;
    char c[len];
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (i < lenA)
        {
            c[i] = a[i];
        }
        else
        {
            c[i] = b[j];
            j++;
        }
    }
    printf("%s\n", c);
    // ----------------3rd line logic------------------
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;

    printf("%s %s\n", a, b);
    return 0;
}