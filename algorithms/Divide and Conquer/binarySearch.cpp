#include <stdio.h>
using namespace std;

bool binarySearch(int a[], int l, int r, int t) {
    if (l == r && a[l] == t) return true;
    if (l == r && a[l] != t) return false;

    int mid = (l + r) / 2;
    if (a[mid] > t) binarySearch(a, l, mid, t);
    else if (a[mid] < t) binarySearch(a, mid+1, r, t);
    else return true;
}

int main() {

    int a[] = {};

    printf("%d", binarySearch(a, 0, 0, 12)? 1 : 0);
}
