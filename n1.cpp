#include <iostream>
#include <algorithm>

const int ROWS = 22;
const int COLS = 2;

void findMaxSumRows(const int array[ROWS][COLS], int& row1, int& row2) {
    int maxSum = 0;

    for (int i = 0; i < ROWS - 1; ++i) {
        int currentSum = array[i][0] + array[i][1] + array[i + 1][0] + array[i + 1][1];
        if (currentSum > maxSum) {
            maxSum = currentSum;
            row1 = i;
            row2 = i + 1;
        }
    }
}

void sortRowDescending(int row[COLS]) {
    std::sort(row, row + COLS, std::greater<int>());
}

int main() {
    int array[ROWS][COLS];

    std::cout << "Enter the elements of the 2D array:" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << "Enter element at position [" << i << "][" << j << "]: ";
            std::cin >> array[i][j];
        }
    }

    int maxSumRow1, maxSumRow2;

    findMaxSumRows(array, maxSumRow1, maxSumRow2);

    std::cout << "Rows with the maximum sum: " << maxSumRow1 << " and " << maxSumRow2 << std::endl;

    for (int i = 0; i < ROWS; ++i) {
        sortRowDescending(array[i]);
    }

    std::cout << "Sorted 2D array:" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
