#include<stdio.h>
#include<string.h>
int main(){
    
    char s[100001];
    scanf("%s", &s);
    for(int i = 0; i< strlen(s); i++){

        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = s[i] - 'a' + 'A';
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] - 'A' + 'a';
        }
        else if (s[i] == ','){
            s[i] = ' ';
        }
    }
    printf("%s", s);
    return 0;
}