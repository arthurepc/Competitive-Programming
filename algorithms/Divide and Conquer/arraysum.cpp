#include <stdio.h>
using namespace std;

int arraySum(int a[], int l, int r) {
    if (sizeof(a)/sizeof(*a) == 0) return 0;

    if (l == r) {
        return a[l];
    }

    int mid = (l + r) / 2;
    int left = arraySum(a, l, mid);
    int right = arraySum(a, mid + 1, r);

    int sum = left + right;

    return sum;
}


int main() {
    int a[] = {};

    printf("%d", arraySum(a, 0, 0));

    return 0;
}
