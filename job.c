#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int n = 5;
char id[MAX][5] = {"J1", "J2", "J3", "J4", "J5"};
int deadline[MAX] = {2, 1, 2, 1, 3};
int profit[MAX] = {100, 19, 27, 25, 15};

// Swap function for 3 parallel arrays
void swap(int a, int b) {
    int temp;

    // Swap profit
    temp = profit[a];
    profit[a] = profit[b];
    profit[b] = temp;

    // Swap deadline
    temp = deadline[a];
    deadline[a] = deadline[b];
    deadline[b] = temp;

    // Swap id
    char tempStr[5];
    strcpy(tempStr, id[a]);
    strcpy(id[a], id[b]);
    strcpy(id[b], tempStr);
}

// Sort by profit descending using bubble sort or qsort-style loop
void sortByProfit() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (profit[i] < profit[j]) {
                swap(i, j);
            }
        }
    }
}

void jobSequencing() {
    sortByProfit();

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }

    int slot[MAX] = {0};         // slot[i] = 1 if occupied
    char result[MAX][5];         // result[i] stores job id
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = deadline[i]; j > 0; j--) {
            if (!slot[j]) {
                slot[j] = 1;
                strcpy(result[j], id[i]);
                totalProfit += profit[i];
                break;
            }
        }
    }

    printf("Job Order: ");
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i])
            printf("%s ", result[i]);
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    jobSequencing();
    return 0;
}
