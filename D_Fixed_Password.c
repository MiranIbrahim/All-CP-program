#include<stdio.h>

int main(){
    
    while(1){
        int n;
        scanf("%d", &n);
        if(n!=1999){
            printf("Wrong\n");
        }
        else{
            printf("Correct\n");
            break;
        }
    }
    return 0;
}