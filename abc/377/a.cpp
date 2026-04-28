#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    string s;
    cin >> s;

    bool a = false;
    bool b = false;
    bool c = false;

    rep (i, 3) {
        if (s[i] == 'A') {
            a = true;
        }
        else if (s[i] == 'B') {
            b = true;
        }
        else if (s[i] == 'C') {
            c = true;
        }
    }

    if (a && b && c) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }

    return 0;
}