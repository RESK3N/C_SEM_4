//Insertion Sort
#include<stdio.h>
void sort(int arr[], int n){
    int key,j;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
        arr[j+1]=arr[j];
        j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[]={5,4,10,1,2,6};
    int len=sizeof(arr)/sizeof(arr[0]);
    printf("Before Sorting :\n");   
    for(int i=0;i<len;i++)
        printf("%d\t",arr[i]);
    sort(arr,len);
    printf("\nAfter Sorting :\n");
    for(int i=0;i<len;i++)
    printf("%d\t",arr[i]);
}