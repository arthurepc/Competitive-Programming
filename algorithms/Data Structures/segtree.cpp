#include <stdio.h>
using namespace std;

//SEGMENT TREE IMPLEMENTATION WITH THE SUM OPERATION

const int N = 200000;
int seg[4 * N], arr[N];

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }

    int m = (l + r) / 2;
    build(2 * node, l, m);
    build(2 * node + 1, m + 1, r);

    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

void update(int node, int l, int r, int pos, int val) {
    if (l == r) {
        seg[node] = val;
        return;
    }

    int m = (l + r) / 2;
    if (pos <= m) update(2*node,l,m,pos,val);
    else update(2*node + 1,m+1,r,pos,val);

    seg[node] = seg[2*node] + seg[2*node + 1];
}

int query(int node, int l, int r, int x, int y) {
    if (l > y || r < x) return 0;
    if (l >= x && r <= y) return seg[node];

    int m = (l + r) / 2;
    int ansl = query(2 * node, l, m, x, y);
    int ansr = query(2*node+1, m + 1, r, x, y);

    return ansl + ansr;
}

int main() {

    return 0;
}
