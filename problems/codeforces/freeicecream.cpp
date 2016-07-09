#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    long long int n, x, d;
    string c;

    scanf("%I64d %I64d", &n, &x);

    long long int distressed = 0;
    for (int i = 0; i < n; i++) {
        cin >> c;
        scanf("%I64d", &d);

        if (c == "+") x += d;
        else if (c == "-" && x - d >= 0) {
            x -= d;
        } else if (x - d < 0) {
            distressed++;
        }
    }

    printf("%I64d %I64d", x, distressed);

    return 0;
}
