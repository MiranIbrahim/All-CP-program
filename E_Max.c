#include<stdio.h>

int main(){
    
    int n, max = -1;
    scanf("%d", &n);
    while(n--){
        int inp;
        scanf("%d", &inp);
        if(inp>max){
            max = inp;
        }
    }
    printf("%d\n", max);
    return 0;
}