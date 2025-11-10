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
    }

    for (int i = 0; i < L; i++) {
        int r = rand() % 11;
        int temp_y;

        if (r <= 3) {
            temp_y = X[i];
        } else if (r <= 5) {
            temp_y = X[i] - 1;
        } else if (r <= 7) {
            temp_y = X[i] + 1;
        } else if (r <= 9) {
            temp_y = X[i] - 2;
        } else {
            temp_y = X[i] + 2;
        }

        if (temp_y < 0) {
            temp_y = 0;
        }
        if (temp_y >= N) {
            temp_y = N - 1;
        }

        Y[i] = temp_y;
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