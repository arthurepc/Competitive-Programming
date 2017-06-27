#include <stdio.h>

#define N 5
using namespace std;

int main() {
    int m[N][N], row, column;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &m[i][j]);

            if (m[i][j]) {
                row = i;
                column = j;
            }
        }
    }

    int c = 0;
    if (row > 2) {
        c += row - 2;
    } else if (row < 2) {
        c += 2 - row;
    }

    if (column > 2) {
        c += column - 2;
    } else if (column < 2) {
        c += 2 - column;
    }

    printf("%d", c);

    return 0;
}
