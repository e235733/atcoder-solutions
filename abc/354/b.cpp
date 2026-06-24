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

    vector<string> S(n);
    int T = 0;
    rep (i, n) {
        int c;
        cin >> S[i] >> c;
        T += c;
    }

    sort(S.begin(), S.end());
    cout << S[T % n] << '\n';

    return 0;
}