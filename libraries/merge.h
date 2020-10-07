#pragma once

int *merge_two_arrays(const int *arr1, const int *arr2, unsigned int length1, unsigned int length2) {
    int *arr = new int[length1 + length2];
    int i1 = 0, i2 = 0, i = 0;

    while (i1 < length1 && i2 < length2) {
        if (arr1[i1] < arr2[i2]) {
            arr[i++] = arr1[i1++];
        } else {
            arr[i++] = arr2[i2++];
        }
    }

    for (unsigned int j = i1; j < length1; ++j) {
        arr[i++] = arr1[i1++];
    }

    for (unsigned int j = i2; j < length2; ++j) {
        arr[i++] = arr2[i2++];
    }

    return arr;
}

int *merge_arrays(int **_arrays, unsigned int rows, unsigned int cols) {
    unsigned int step = 1;

    int **arrays = new int *[rows];
    for (unsigned int i = 0; i < rows; ++i) {
        arrays[i] = new int[cols];
        for (unsigned int j = 0; j < cols; ++j) {
            arrays[i][j] = _arrays[i][j];
        }
    }

    auto *lengths = new unsigned int[rows];
    for (unsigned int i = 0; i < rows; ++i) {
        lengths[i] = cols;
    }

    while (step < rows) {
        for (unsigned int i = step; i < rows; i += step * 2) {
            int *temp = merge_two_arrays(arrays[i], arrays[i - step], lengths[i], lengths[i - step]);
            delete arrays[i];
            delete arrays[i - step];
            arrays[i - step] = temp;
            lengths[i - step] = lengths[i - step] + lengths[i];
        }
        step += step;
    }

    delete[] lengths;
    return arrays[0];
}