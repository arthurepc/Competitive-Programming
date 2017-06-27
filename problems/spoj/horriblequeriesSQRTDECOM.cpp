#include <stdio.h>
#include <math.h>
using namespace std;

long long int arr[100000], blocks[1000], lazy[1000];

void build(int n) {
    int root = floor(sqrt(n));

    for (int i = 0; i < n; i++) {
        blocks[i/root] += arr[i];
    }
}

int main() {
    int t, n, c, l, r, q;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &c);

        for (int j = 0; j < c; j++) {
            scanf("%d", &q);

            if (q) {
                scanf("%d %d", &l, &r);
            } else {
                scanf("%d %d %d", &l, &r, &v);

            }
        }
    }

    return 0;
}

