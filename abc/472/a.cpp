#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

    string S;
    cin >> S;
    for (char c : S) {
        if (c - 'A' == 0) {
            cout << 'A';
        }
        else {
            cout << '.';
        }
    }
    cout << '\n';

    return 0;
}