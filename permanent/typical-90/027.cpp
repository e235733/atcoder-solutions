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

    int n;
    cin >> n;

    unordered_set<string> names;
    rep (i, n) {
        string s;
        cin >> s;
        debug(s);
        if (!names.contains(s)) {
            cout << i + 1 << '\n'; 
            names.insert(s);
        }
    }

    return 0;
}