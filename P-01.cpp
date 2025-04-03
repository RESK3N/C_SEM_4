//31/01/25
//Wap in C to print the elements of a 1D array in both forward and reverse directions using pointer
#include <iostream>
using namespace std;
int main() {
    int i=0;
    int a[]={12,13,14,20,30,40};
    while(i<6){
        printf("%d\t",*(a+i));
        i++;
    }printf("\n");
    i=0;
    while(i<6) {
        printf("%d\t",*(a+5-i));
        i++;
    }
    return 0;
}
