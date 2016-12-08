#include <stdio.h>
using namespace std;

int main() {
    int n, x, y, z;

    scanf("%d", &n);

    int fx = 0, fy = 0, fz = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &z);

        fx += x;
        fy += y;
        fz += z;
    }

    if (fx == 0 && fy == 0 && fz == 0) printf("YES\n");
    else printf("NO\n");


    return 0;
}
