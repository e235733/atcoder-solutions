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
    map<int, vector<int>> aw;
    vector<int> A(n), W(n);
    rep (i, n) cin >> A[i];
    rep (i, n) cin >> W[i];

    int ans = 0;
    rep (i, n) aw[A[i]].push_back(W[i]);
    for (auto [a, w] : aw) {
        sort(w.begin(), w.end());
        int len = w.size();
        rep (i, len-1) {
            ans += w[i];
        } 
    }

    cout << ans << '\n';

    return 0;
}