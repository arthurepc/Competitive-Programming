#include <stdio.h>
using namespace std;

int main() {
    int h1,h2,m1,m2;

    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);

    int ansh = 0, ansm = 0, ans = 0;
    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;

    //printf("t1: %d\nt2: %d", t1, t2);

    if (t1 < t2) {
        ans = t2 - t1;
    } else {
        ans = ((24 * 60) - t1) + t2;
    }

    ansh = ans / 60;
    ansm = ans % 60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", ansh, ansm);

    return 0;
}
