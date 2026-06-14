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

    int n, s;
    cin >> n >> s;

    vector<int> A(n), B(n);
    rep (i, n) cin >> A[i] >> B[i];

    vector<unordered_map<int, char>> m(n+1);
    m[0] = {{0, '.'}};
    rep (i, n) {
        for (auto [p, c] : m[i]) {
            if (p+A[i] <= s) m[i+1][p+A[i]] = 'A';
            if (p+B[i] <= s) m[i+1][p+B[i]] = 'B';
        }
    }
    debug(m);

    if (!m[n].contains(s)) {
        cout << "Impossible" << '\n';
        return 0;
    }

    int cp = s;
    string result = "";
    rep (i, n) {
        debug(cp, m[n-i][cp]);
        result.push_back(m[n-i][cp]);
        cp -= m[n-i][cp] == 'A' ? A[n-i-1] : B[n-i-1];
    }
    debug(result);

    reverse(result.begin(), result.end());
    cout << result << '\n';

    return 0;
}