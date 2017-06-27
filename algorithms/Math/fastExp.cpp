#include <stdio.h>
using namespace std;

int fastExp(int base, int exp) {
    if (exp == 0) return 1;
    else {
        int res = fastExp(base, exp / 2);
        res *= res;
                //printf("res = %d", res);

        if (exp % 2 == 1) res *= base;
        return res;
    }
}

int main() {

    printf("%d", fastExp(2, 30));

    return 0;
}
