#pragma once

#include <cstdlib>
#include <random>
#include <iostream>
#include <functional>

const size_t MATRIX_SIZE = 1 << 10;
const size_t LOOP_REPETITION = 1;

int original[MATRIX_SIZE][MATRIX_SIZE];
int result[MATRIX_SIZE][MATRIX_SIZE];

void init() {
    std::mt19937 rng;
    for (size_t i = 0; i < MATRIX_SIZE; i++) {
        for (size_t j = 0; j < MATRIX_SIZE; j++) {
            original[i][j] = rng();
        }
    }
}

void plain() {
    for (size_t i = 0; i < MATRIX_SIZE; i++) {
        for (size_t j = 0; j < MATRIX_SIZE; j++) {
            result[i][j] = original[j][i];
        }
    }
}

void aware() {
    const size_t BLOCK_SIZE = 8;
    for (size_t row_start = 0; row_start < MATRIX_SIZE; row_start += BLOCK_SIZE) {
        for (size_t column_start = 0; column_start < MATRIX_SIZE; column_start += BLOCK_SIZE) {
            for (size_t i = row_start; i < row_start + BLOCK_SIZE && i < MATRIX_SIZE; i++) {
                for (size_t j = column_start; j < column_start + BLOCK_SIZE && j < MATRIX_SIZE; j++) {
                    result[i][j] = original[j][i];
                }
            }
        }
    }
}

/**
 * Row and column numbers refer to the result matrix. The row and column numbers of the original matrix should be swapped. 
 */
void oblivious_r(size_t start_row, size_t end_row, size_t start_column, size_t end_column) {
    int num_rows = end_row - start_row, num_columns = end_column - start_column;
    if (num_rows == 1 && num_columns == 1) {
        result[start_row][start_column] = original[start_column][start_row];
        return;
    }
    if (num_rows >= num_columns) {
        int mid_row = (start_row + end_row) / 2;
        oblivious_r(start_row, mid_row, start_column, end_column);
        oblivious_r(mid_row, end_row, start_column, end_column);
    } else {
        int mid_column = (start_column + end_column) / 2;
        oblivious_r(start_row, end_row, start_column, mid_column);
        oblivious_r(start_row, end_row, mid_column, end_column);
    }
}

void oblivious() {
    oblivious_r(0, MATRIX_SIZE, 0, MATRIX_SIZE);
}

void run(std::function<void()> f) {
    init();
    for (size_t i = 0; i < LOOP_REPETITION; i++) {
        f();
    }
} 
