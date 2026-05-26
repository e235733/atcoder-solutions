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

    int count = 0;
    rep (i, 12) {
        string s;
        cin >> s;

        if (i+1 == (int)s.size()) {
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}