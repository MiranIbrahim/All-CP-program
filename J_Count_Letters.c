#include<stdio.h>
#include<string.h>
int main(){
    
    char c;
    int sum[26] = {0};
    while(scanf("%c ", &c) != EOF){
        int val = c - 'a';
        sum[val]++;
    }
    for(int i = 0; i<26; i++){
        if(sum[i] > 0){
            printf("%c : %d\n", i+'a', sum[i]);
        }
    }
    return 0;
}