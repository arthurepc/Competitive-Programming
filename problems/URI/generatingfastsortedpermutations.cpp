#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int n;
string s;

bool valid(int i, int j) {
    for (int k = 0; k < i; k++) {
        if (s[k] == 'a' + j) {
            return false;
        }
    }

    return true;
}

void permutations(int i, int l) {
    if (i == l - 1) {
        for (int j = 0; j < l; j++) {
            printf("%c", s[j]);
        }
        printf("\n");
        return;
    }

    for (int j = 0; j < l; j++) {
        if (valid(i + 1, j)) {
            s[i + 1] = 'a' + j;
            //printf("%d", j - 'a');
            //printf("ad ");
            permutations(i + 1, l);
        }
    }
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        cin >> s;

        permutations(-1, s.size());

        printf("\n");
    }

    return 0;
}
