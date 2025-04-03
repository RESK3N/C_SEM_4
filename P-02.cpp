//Wap in C to print the elements and its address of a 2D array in both forward and reverse direction
//31/01/25
#include <iostream>
using namespace std;
int main() {
    int i=0;
    int a[]={12,13,14,20,30,40};
    while(i<6){
        printf("%d\t",*(a+i));
        printf("@ %u\t\t",(a+i));
        i++;
    }printf("\n");
    i=0;
    while(i<6) {
        printf("%d\t",*(a+5-i));
        printf("@ %u\t\t",(a+5-i));

        i++;
    }
    return 0;
}
