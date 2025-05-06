//Quick Sort
#include<stdio.h>
int partition(int arr[],int lb,int ub){
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end) {
            //swapping
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    //swapping
    arr[lb]=arr[end];
    arr[end]=pivot;
    //retuning
    return end;
}
void sort(int arr[],int lb,int ub){
    if(lb<ub){
        int pivot= partition(arr,lb,ub);
        sort(arr,lb,pivot-1);
        sort(arr,pivot+1,ub);
    }
}
int main(){
    int arr[]={5,4,10,33,1,2,6,22,3,7,8};
    int len=sizeof(arr)/sizeof(arr[0]);
    printf("Before Sorting :\n");
    for(int i=0;i<len;i++)
        printf("%d\t",arr[i]);
    sort(arr,0,len-1);
    printf("\nAfter Sorting :\n");
    for(int i=0;i<len;i++)
        printf("%d\t",arr[i]);
}