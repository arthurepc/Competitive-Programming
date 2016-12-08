#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int n,n1,n2, a[100100];

    scanf("%d %d %d", &n, &n1, &n2);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a+n);

    double c1 = 0.0, c2 = 0.0;
    int i = n - 1;
    int bn1 = n1, bn2 = n2;
    if (n1 < n2) {
        while (n1 > 0) {
            c1 += a[i];
            i--;
            n1--;
        }

        while (n2 > 0) {
            c2 += a[i];
            i--;
            n2--;
        }
    } else {
        while (n2 > 0) {
            c2 += a[i];
            i--;
            n2--;
        }

        while (n1 > 0) {
            c1 += a[i];
            i--;
            n1--;
        }
    }
    //printf("t ==== %lf", c1 / bn1);

    double ans = (c1 / bn1) + (c2 / bn2);
    printf("%lf", ans);

    return 0;
}
