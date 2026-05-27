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

    char s, t, u;
    cin >> s >> t >> u;

    if (s == '>') {
        if (t == '>') {
            if (u == '>') {
                cout << 'B' << '\n';
            }
            else {
                cout << 'C' << '\n';
            }
        }
        else {
            cout << 'A' << '\n';
        }
    }
    else {
        if (t == '>') {
            cout << 'A' << '\n';
        }
        else {
            if (u == '>') {
                cout << 'C' << '\n';
            }
            else {
                cout << 'B' << '\n';
            }
        }
    }

    return 0;
}