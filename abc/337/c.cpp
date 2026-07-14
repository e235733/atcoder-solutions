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

    int n;
    cin >> n;

    vector<int> to(n+1, -1);
    rep (i, n) {
        int a;
        cin >> a;
        if (a == -1) to[0] = i + 1;
        else to[a] = i + 1;
    }

    int i = 0;
    while (to[i] != -1) {
        cout << to[i] << ' ';
        i = to[i];
    }
    cout << '\n';

    return 0;
}