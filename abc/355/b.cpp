#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int inf = 1 << 10;

int n, m;
vector<pair<int, bool>> A;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> m;
    A.reserve(n+m);
    rep (i, n) {
        int a;
        cin >> a;
        A.push_back({a, true});
    }
    rep (i, m) {
        int b;
        cin >> b;
        A.push_back({b, false});
    }

    sort(A.begin(), A.end());
    rep (i, n+m-1) {
        if (A[i].second && A[i+1].second) {
            cout << "Yes" << '\n';
            return 0;
        }
    }

    cout << "No" << '\n';

    return 0;
}