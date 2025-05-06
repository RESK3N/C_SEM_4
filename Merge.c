#include <stdio.h>
void merge(int arr[],int left,int mid,int right){
    int i,j,k;
    int l1,l2;
    l1=mid-left+1;//length of left subarray
    l2=right-mid;//length of right subarray
    int larr[l1],rarr[l2];
    //dividing arr into left array larr and right array rarr
    for(i=0;i<l1;i++){
        larr[i]=arr[left+i];
    }
    for(j=0;j<l2;j++){
        rarr[j]=arr[mid+1+j];
    }
    i=0,j=0,k=left;
    while(i<l1 && j<l2){
        if(larr[i]<=rarr[j]){
            arr[k]=larr[i];
            i++;
        }else{
            arr[k]=rarr[j];
            j++;
        }
        k++;
    }
    while(i<l1){
        arr[k]=larr[i];
        i++;
        k++;
    }
    while(j<l2){
        arr[k]=rarr[j];
        j++;
        k++;
    }

}
void mergesort(int arr[],int left , int right){

    if(left<right){
        int mid=left+(right-left)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);
    }

}
void print(int arr[],int n){
    for (int i = 0; i < n; ++i) {
        printf("%d\t\t",arr[i]);

    }
}

int main(){
    int n;
    printf("Enter Length of array : ");
    scanf("%d",&n);
    int arr[n] ;
    for (int i = 0; i < n; ++i) {
        printf("\nEnter %d element : ",i+1);
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    print(arr,n);

}