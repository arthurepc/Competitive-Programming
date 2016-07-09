#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int n, d, c;
    string s;

    scanf("%d %d", &n, &d);

    c = 0;
    int ans = 0;
    for (int i = 0; i < d; i++) {
        cin >> s;

        bool achou = false;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '0') {
                achou = true;
                break;
            }
        }

        if (achou) {
            c++;
            if (i == d - 1 && c > ans) ans = c;
        }
        else {
            //printf("%d %d\n", ans, c);
            if (c > ans) ans = c;
            c = 0;
        }
    }

    printf("%d", ans);

    return 0;
}
