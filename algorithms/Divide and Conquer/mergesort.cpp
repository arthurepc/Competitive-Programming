#include <stdio.h>
#include <vector>
using namespace std;

void _merge(int a[], int l, int mid, int r) {
    vector<int> aux(r - l + 1);
    //int aux[30];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) {
            aux[k] = a[i];
            i++;
        }
        else {
            aux[k] = a[j];
            j++;
        }

        k++;
    }

    while (i <= mid) {
        aux[k] = a[i];
        k++;
        i++;
    }

    while (j <= r) {
        aux[k] = a[j];
        k++;
        j++;
    }

    for (int i = l; i <= r; i++) {
        a[i] = aux[i - l];
    }
}

void mergeSort(int a[], int l, int r) {
    if (l == r)
        return;

    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    _merge(a, l, mid, r);
}

int main() {

    int a[] = {9,8,7,6,5,4,3,2,1};

    mergeSort(a, 0, 8);

    for (int i = 0; i < 8; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
