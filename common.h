#pragma once

#include <cstdlib>
#include <random>
#include <iostream>

const size_t MATRIX_SIZE = 1 << 10;

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
    const int BLOCK_SIZE = 8;
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
