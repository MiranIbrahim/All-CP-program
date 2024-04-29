#include<stdio.h>

int main(){
    
    int n; 
    scanf("%d", &n);
    int arr[n+1];
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int even = 0, odd = 0, pos = 0, neg = 0;
    for(int i = 0; i<n; i++){
        if(arr[i]%2==0){
            even ++;
        }
        if(arr[i]%2!=0){
            odd ++;
        }
        if (arr[i]<0){
            neg++;
        }
        if(arr[i]>0){
            pos++;
        }
    }
    printf("Even: %d\n", even);
    printf("Odd: %d\n", odd);
    printf("Positive: %d\n", pos);
    printf("Negative: %d\n", neg);
    return 0;
}