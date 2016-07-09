#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, ans;

    cin >> s;

    ans = s;
    for (int i = s.length() - 1; i >= 0; i--) {
        ans += s[i];
    }

    for (int i = 0; i < ans.length(); i++) {
        printf("%c", ans[i]);
    }

    return 0;
}
