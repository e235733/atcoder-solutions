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
    char c1, c2;
    string s;

    cin >> n >> c1 >> c2 >> s;

    for (char& c : s) {
        if (c != c1) {
            c = c2;
        }
    }
    cout << s << '\n';

    return 0;
}