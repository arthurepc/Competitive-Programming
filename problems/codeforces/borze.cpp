#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;

    cin >> s;

    int i = 0;
    while (i < s.length()) {
        if (s[i] == '.') {
            printf("0");
            i++;
        } else if (s[i] == '-' && s[i + 1] == '.') {
            printf("1");
            i+=2;
        } else {
            printf("2");
            i+=2;
        }
    }

    return 0;
}
