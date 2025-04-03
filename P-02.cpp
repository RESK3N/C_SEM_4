//Wap in C to print the elements and its address of a 2D array in both forward and reverse direction
//31/01/25
#include <iostream>
using namespace std;
int main() {
    int arr[2][5]={{1,2,3,4,5},{6,7,8,9,10}};
    int r=5,c=2;
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            printf("%d\t",*(*(arr+i)+j));
            printf("@ %u ,\t",*(arr+i+j));
        }
        printf("\n");
    }
    
    for(int i=c-1;i>=0;i--){
        for(int j=r-1;j>=0;j--){
            printf("%d\t",*(*(arr+i)+j));
            printf("@ %u ,\t",*(arr+i+j));
        }
        printf("\n");
    }
}
