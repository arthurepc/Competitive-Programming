#include <stdio.h>
using namespace std;

int main() {
    int t, n;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);

        if (n % 2 == 0) {
            printf("1\n");
        } else printf("9\n");
    }

    return 0;
}
