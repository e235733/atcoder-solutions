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

    int length = s.size();
    ll count = 0;
    rep (i, length) {
        if (s[i] == 'C') {
            count += min(i+1, length-i);
        }
    }
    cout << count << '\n';

    return 0;
}