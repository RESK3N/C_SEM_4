//power of anumber using recursion
#include<stdio.h>
int powr(int a, int b){
    if(b>0)
        return a*powr(a,b-1);
    else
        return 1;
}
int main(){
    int a=2,b=10;
    printf("%d",powr(a,b));
}