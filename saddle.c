//Saddle point of a matrix
// Created by Pritam Mondal on 12/04/25.
//
#include <stdio.h>

#define ROW 3
#define COL 3

void findSaddlePoint(int mat[ROW][COL]) {
    int found = 0;

    for (int i = 0; i < ROW; i++) {
        int minRow = mat[i][0];
        int colIndex = 0;

        // Find the minimum in the current row
        for (int j = 1; j < COL; j++) {
            if (mat[i][j] < minRow) {
                minRow = mat[i][j];
                colIndex = j;
            }
        }
        

        // Check if it's the maximum in its column
        int k;
        for (k = 0; k < ROW; k++) {
            if (mat[k][colIndex] > minRow)
                break;
        }

        if (k == ROW) {
            printf("Saddle Point found at (%d, %d): %d\n", i, colIndex, minRow);
            found = 1;
        }
    }

    if (!found)
        printf("No Saddle Point found in the matrix.\n");
}

int main() {
    int mat[ROW][COL] = {
            {1, 2, 3},
            {4, 5, 1},
            {7, 8, 9}
    };

    findSaddlePoint(mat);

    return 0;
}
