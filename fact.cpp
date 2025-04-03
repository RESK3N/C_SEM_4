// factorial using recursion
#include<stdio.h>
int fact(int n){
    if(n>1)
    return n*fact(n-1);
    else
        return 1;
}
int main(){
    int n=4;
    printf("%d",fact(n));
}