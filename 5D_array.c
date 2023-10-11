#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 2, y = 3, z = 4, w = 5, v = 6; 
    int***** array5D;

    array5D = (int*****)malloc(x * sizeof(int****));
    for (int i = 0; i < x; ++i) {
        array5D[i] = (int****)malloc(y * sizeof(int***));
        for (int j = 0; j < y; ++j) {
            array5D[i][j] = (int***)malloc(z * sizeof(int**));
            for (int k = 0; k < z; ++k) {
                array5D[i][j][k] = (int**)malloc(w * sizeof(int*));
                for (int l = 0; l < w; ++l) {
                    array5D[i][j][k][l] = (int*)malloc(v * sizeof(int));
                }
            }
        }
    }

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                for (int l = 0; l < w; ++l) {
                    for (int m = 0; m < v; ++m) {
                        array5D[i][j][k][l][m] = i + j + k + l + m;
                        printf("array5D[%d][%d][%d][%d][%d] = %d\t\t\t", i, j, k, l, m, array5D[i][j][k][l][m]);
                    }
                }
            }
        }
    }

    return 0;
}
