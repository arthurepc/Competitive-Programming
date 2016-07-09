#include <stdio.h>
using namespace std;

int main() {
    int n, a[110];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    while (1) {
        bool trocou = false;

        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;

                printf("%d %d\n", i + 1, i + 2);
                trocou = true;
            }
        }

        if (!trocou) break;
    }

    return 0;
}
