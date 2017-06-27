#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int n, t;
    string q;

    scanf("%d %d", &n, &t);

    cin >> q;

    for (int i = 0; i < t; i++) {
        int j = 0;
        bool flag = false;
        while (j < n) {
            if (q[j] == 'B' && q[j + 1] == 'G') {
                flag = true;
                swap(q[j], q[j+1]);
                j += 2;
                continue;
            }
            j++;
        }
    }

    cout << q;

    return 0;
}
