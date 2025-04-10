#include <stdio.h>
void sort(int arr[],int n){

    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[6]={50,30,40,20,10,6};
    sort(arr,6);
    for (int i = 0; i < 6; i++){
        printf("%d\t",arr[i]);
    }
}