#include <stdio.h>
using namespace std;

int main() {
    long long int n;

    scanf("%lld", &n);

    while (n != 0) {
        printf("%d", n % 10);
        n /= 10;
    }

    printf("\n");
    return 0;
}
