#include "common.h"
#include <cstring>
#include <iostream>

int copy[MATRIX_SIZE][MATRIX_SIZE];

int main() {
    init();
    plain();
    memcpy(copy, result, sizeof(copy));
    oblivious();
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (copy[i][j] != result[i][j]) {
                std::cout << "Mismatch at i = " << i << ", j = " << j << '\n';
            }
        }
    }
    return 0;
}
