#pragma once

#include <cstdlib>
#include <random>
#include <iostream>

const size_t MATRIX_SIZE = 1 << 10;

int matrix[MATRIX_SIZE][MATRIX_SIZE];
int target[MATRIX_SIZE][MATRIX_SIZE];

void init() {
    std::mt19937 rng;
    for (size_t i = 0; i < MATRIX_SIZE; i++) {
        for (size_t j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = rng();
        }
    }
}

void plain() {
    for (size_t i = 0; i < MATRIX_SIZE; i++) {
        for (size_t j = 0; j < MATRIX_SIZE; j++) {
            target[i][j] = matrix[j][i];
        }
    }
}
