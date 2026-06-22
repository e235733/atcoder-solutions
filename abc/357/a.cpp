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

    int n, m;
    cin >> n >> m;
    int count = 0;
    rep (i, n) {
        int h;
        cin >> h;

        if (m >= h) {
            count++;
            m -= h;
        } 
        else break;
    }

    cout << count << '\n';

    return 0;
}