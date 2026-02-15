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

    int a, b;
    cin >> a >> b;

    cout << "A:";
    rep (i, a) {
        cout << ']';
    }
    cout << endl;

    cout << "B:";
    rep (i, b) {
        cout << ']';
    }
    cout << endl;

    return 0;
}