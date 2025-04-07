//Selection Sort
#include <stdio.h>
void sort(int arr[] , int n){
    for(int i=0 ; i<n ; i++){
        int temp=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[temp])
                temp=j;
        }
        int swap=arr[temp];
        arr[temp]=arr[i];
        arr[i]=swap;
    }
}
int main(){
    int arr[]={5,4,10,33,1,2,6,22,3,7};
    int len=sizeof(arr)/sizeof(arr[0]);
    printf("Before Sorting :\n");
    for(int i=0;i<len;i++)
        printf("%d\t",arr[i]);
    sort(arr,len);
    printf("\nAfter Sorting :\n");
    for(int i=0;i<len;i++)
        printf("%d\t",arr[i]);
}