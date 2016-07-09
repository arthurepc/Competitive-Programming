#include <stdio.h>
#include <math.h>
using namespace std;

long long int n, arr[100100];

long long int query(int l, int r, int root, long long int a[], long long int lazy[]) {
    long long int sum = 0;
    for (int i = l; i <= r; i++) {
        if (i % root == 0 && i + root - 1 <= r) {
            sum += a[i/root];
            i += root - 1;
        } else {
            sum += arr[i] + lazy[i/root]; // FAZER LAZY PROPAGATION AQUI
        }
    }

    return sum;
}

void update(int l, int r, long long int v, long long int root, long long int a[], long long int lazy[]) {
    for (int i = l; i <= r; i++) {
        if (i % root == 0 && i + root - 1 <= r) {
            a[i/root] += v * root;
            lazy[i/root] += v;
            i += root - 1;
        } else {
            arr[i] += v;
            a[i/root] += v;
        }
    }
}

int main() {
    int t, c, q, l, r;

    scanf("%d", &t);

    for (int k = 0; k < t; k++) {
        scanf("%d %d", &n, &c);

        for (int i = 0; i < n; i++)
            arr[i] = 0;

        long long int root = ceil(sqrt(n));

        long long int a[root], lazy[root];


        for (int i = 0; i < root; i++)
            a[i] = 0;

        for (int i = 0; i < root; i++)
            lazy[i] = 0;

        for (int i = 0; i < c; i++) {
            scanf("%d %d %d", &q, &l, &r);
            if (q) {
                printf("%lld\n", query(l - 1, r - 1, root, a, lazy));
            } else {
                long long int v;
                scanf("%lld", &v);
                update(l - 1, r - 1, v, root, a, lazy);
            }
/*
            printf("\nblocos\n");
            for (int j = 0; j < root; j++)
                printf("%d ", a[j]);

            printf("\n");
            printf("arr\n");
            for (int j = 0; j < n; j++)
                printf("%d ", arr[j]);

            printf("\n");
            printf("lazy\n");
            for (int j = 0; j < root; j++)
                printf("%d ", lazy[j]);*/
        }
    }


    return 0;
}
