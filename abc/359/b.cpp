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
    vector<int> d(n, -1);

    rep (i, n*2) {
        int a;
        cin >> a;
        a--;
        if (d[a] == -1) d[a] = i;
        else d[a] = abs(d[a] - i);
    }

    int count = 0;
    rep (i, n) {
        if (d[i] == 2) count++;
    }

    cout << count << '\n';

    return 0;
}