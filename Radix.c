#include <stdio.h>
int digit(int num,int exp){
    return (num/exp)%10;
}
void InsertionSort(int arr[],int n,int exp){

    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && digit(arr[j],exp)>digit(key,exp)){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int getmax(int arr[],int n){
    int max=0,digit=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    while(max>0){
        max=max/10;
        digit++;
    }
    return digit;
}
void radixsort(int arr[],int n){
    int max=getmax(arr,n);
    for(int i=1;i<=max;i*=10){
        InsertionSort(arr,n,i);
    }
}
int main(){
    int arr[6]={50,30,40,200,10,6};
    radixsort(arr,6);
    for (int i = 0; i < 6; i++){
        printf("%d\t",arr[i]);
    }
}