//fixed radix
#include <stdio.h>
#include <math.h>
#define size 6
int digit(int num,int exp){
    return (num/exp)%10;
}
void insertion(int arr[],int n,int exp){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && digit(arr[j],exp)>digit(key,exp)){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void radix(int arr[],int n,int maxdigit){
        for(int i=1;i<pow(10,maxdigit);i*=10){
            insertion(arr,n,i);
            printf("%d\n",i);
        }
}
int main(){
    int arr[size]={50,30,40,200,10,6};
    int digits=3;
    radix(arr,size,digits);
    for (int i = 0; i < size; i++){
        printf("%d\t",arr[i]);
    }
}