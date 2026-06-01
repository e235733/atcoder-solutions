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

    string x;
    cin >> x;
    int len = x.size();

    if (x[len-1] == '0') {
        if (x[len-2] == '0') {
            if (x[len-3] == '0') {
                rep (i, len-4) {
                    cout << x[i];
                }
                cout << '\n';
            }
            else {
                rep (i, len-2) {
                    cout << x[i];
                }
                cout << '\n';
            }
        }
        else {
            rep (i, len-1) {
                cout << x[i];
            }
            cout << '\n';
        }
    }
    else {
        cout << x << '\n';
    }

    return 0;
}