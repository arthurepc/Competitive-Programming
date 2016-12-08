#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 200100;
int seg[4 * N], arr[N];

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }

    int m = (l + r) / 2;
    build(2 * node, l, m);
    build(2 * node + 1, m + 1, r);

    seg[node] = seg[2 * node] * seg[2 * node + 1];
}

void update(int node, int l, int r, int pos, int val) {
    if (l == r) {
        seg[node] = val;
        return;
    }

    int m = (l + r) / 2;
    if (pos <= m) update(2*node,l,m,pos,val);
    else update(2*node + 1,m+1,r,pos,val);

    seg[node] = seg[2*node] * seg[2*node + 1];
}

int query(int node, int l, int r, int x, int y) {
    if (l > y || r < x) return 1;
    if (l >= x && r <= y) return seg[node];

    int m = (l + r) / 2;
    int ansl = query(2 * node, l, m, x, y);
    int ansr = query(2*node+1, m + 1, r, x, y);

    return ansl * ansr;
}

int main() {
    int n, k, x, y;
    string op;

    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);

            if (arr[i] > 0) arr[i] = 1;
            else if (arr[i] < 0) arr[i] = -1;
        }

        build(1,1,n);

        for (int i = 0; i < k; i++) {
            cin >> op;

            if (op == "C") {
                scanf("%d %d", &x, &y);

                if (y < 0) y = -1;
                else if (y > 0) y = 1;

                update(1,1,n,x,y);
            } else {
                scanf("%d %d", &x, &y);

                int ans = query(1,1,n,x,y);
                printf("%c", ans == 0? '0' : ans < 0? '-' : '+');
            }
        }

        printf("\n");
    }
    return 0;
}
