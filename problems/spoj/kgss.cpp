#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


const int N = 100100;
int arr[N];
struct node {
    int max1, max2;

    int unite(node l, node r) {
        int ar[4] = {l.max1, l.max2, r.max1, r.max2};
        sort(ar, ar+4);
        max1 = ar[3];
        max2 = ar[2];
    }

}seg[4 * N];



void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = (node) {arr[l], 0};
        return;
    }

    int m = (l + r) / 2;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);

    seg[id].unite(seg[2 * id], seg[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        seg[id] = (node) {val, 0};
        return;
    }

    int m = (l + r) / 2;
    if (pos <= m) update(2*id,l,m,pos,val);
    else update(2*id + 1,m+1,r,pos,val);

    seg[id].unite(seg[2*id], seg[2*id + 1]);
}

node query(int id, int l, int r, int x, int y) {
    if (l > y || r < x) {
        return (node) {0,0};
    }
    if (l >= x && r <= y) return seg[id];

    int m = (l + r) / 2;
    node ansl = query(2 * id, l, m, x, y);
    node ansr = query(2*id+1, m + 1, r, x, y);

    node ans = (node) {0, 0};
    ans.unite(ansl, ansr);
    return ans;
}

int main() {
    int n, q, x, y;
    string op;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &q);

    build(1, 1, n);

    for (int i = 0; i < q; i++) {
        cin >> op;

        if (op == "U") {
            scanf("%d %d", &x, &y);

            update(1, 1, n, x, y);
        } else {
            scanf("%d %d", &x, &y);

            printf("%d\n", query(1,1,n,x,y).max1 + query(1,1,n,x,y).max2);
        }
    }

    return 0;
}
