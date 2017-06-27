#include <stdio.h>
using namespace std;

int a[100], n;

bool valid(int i, int j) {
    for (int k = 0; k < i; k++) {
        if (a[k] == j) return false;
    }

    return true;
}

void permutations(int i) {
    if (i == n - 1) {
        for (int j = 0; j < n; j++) {
            printf(" %d ", a[j]);
        }
        printf("\n");
        return;
    }

    for (int j = 1; j <= n; j++) {
        if (valid(i + 1, j)) {
            a[i + 1] = j;
            permutations(i + 1);
        }
    }
}

int main() {

    scanf("%d", &n);

    permutations(-1);

    return 0;
}
