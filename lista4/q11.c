#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int N = 7;
    const int L = 14; 

    int X[L];
    int Y[L];
    int M[N][N] = {0};

    srand(time(NULL));

    for (int i = 0; i < L; i++) {
        X[i] = rand() % N;
        Y[i] = rand() % N;
    }

    printf("X = [");
    for (int i = 0; i < L; i++) {
        printf("%d", X[i]);
        if (i < L - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");

    printf("Y = [");
    for (int i = 0; i < L; i++) {
        printf("%d", Y[i]);
        if (i < L - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");

    for (int i = 0; i < L; i++) {
        M[X[i]][Y[i]]++;
    }

    printf("Portanto, M =\n");
    for (int i = 0; i < N; i++) {
        printf("[ ");
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("]\n");
    }

    return 0;
}