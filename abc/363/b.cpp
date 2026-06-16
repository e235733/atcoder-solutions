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

    int n, t, p;
    cin >> n >> t >> p;
    vector<int> l(n);
    rep(i, n) cin >> l[i];

    sort(l.begin(), l.end());
    cout << max(t-l[n-p], 0) << '\n';

    return 0;
}