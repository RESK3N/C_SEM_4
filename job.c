#include<stdio.h>
#include<string.h>

int n=5;
char id[5][5]={"j1", "j2", "j3", "j4", "j5"};
int profit[]={100, 19, 27, 25, 15};
int deadline[]={2, 1, 2, 1, 3};
void swap(int a, int b) {
    int temp;

    temp = profit[a];
    profit[a] = profit[b];
    profit[b] = temp;

    temp = deadline[a];
    deadline[a] = deadline[b];
    deadline[b] = temp;

    char tempStr[5];
    strcpy(tempStr, id[a]);
    strcpy(id[a], id[b]);
    strcpy(id[b], tempStr);
}

void sortbyprofit(){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(profit[i]<profit[j]){
                swap(i,j);
            }
        }
    }
}

void job(){
    sortbyprofit();
    int maxdeadline=0;
    for (int i = 0; i < n; ++i) {
        if(deadline[i]>maxdeadline){
            maxdeadline=deadline[i];
        }
    }
    char result[n][n];
    int slot[5]={0};
    int totalprofit=0;
    for(int i=0;i<n;i++){
        for(int j=deadline[i];j>0;j--){
            if(!slot[j]){
                slot[j]=1;
                strcpy(result[j],id[i]);
                totalprofit+=profit[i];
                break;
            }
        }
    }
    printf("Job Order: ");
    for (int i = 1; i <= maxdeadline; i++) {
        if (slot[i])
            printf("%s ", result[i]);
    }
    printf("\nTotal Profit: %d\n", totalprofit);
}
int main() {
    job();
    return 0;
}