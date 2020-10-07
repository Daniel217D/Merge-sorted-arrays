#include <iostream>

#include "libraries/merge.h"

using std::cin;
using std::cout;

/*
    5 5
    1 4 7 8 9
    2 4 5 7 8
    1 2 3 4 5
    6 7 8 9 10
    3 4 7 8 9
    -> 1 1 2 2 3 3 4 4 4 4 5 5 6 7 7 7 7 8 8 8 8 9 9 9 10
 */

/*
    7 5
    1 4 7 8 9
    2 4 5 7 8
    1 2 3 4 5
    6 7 8 9 10
    3 4 7 8 9
    1 2 3 4 5
    6 7 8 9 10
    -> 1 1 1 2 2 2 3 3 3 4 4 4 4 4 5 5 5 6 6 7 7 7 7 7 8 8 8 8 8 9 9 9 9 10 10
 */
int main() {
    int rows, cols;
    cin >> rows >> cols;

    int **arrays = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        arrays[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            cin >> arrays[i][j];
        }
    }

    int *sorted = merge_arrays(arrays, rows, cols);
    for (int i = 0; i < rows * cols; ++i) {
        cout << sorted[i] << " ";
    }

    return 0;
}
