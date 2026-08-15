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

    vector<int> A(n);
    rep (i, n) cin >> A[i];
    sort(A.begin(), A.end());
    //debug(A);

    vector<int> B;
    while (A.back() > 0) {
        B.push_back(A.back());
        A.pop_back();
    }
    debug(A);
    debug(B);

    ll ans = 0;
    int c = 0;
    while (A.size() || B.size()) {
        if (!A.size()) {
            ans += B.back() - c;
            c = B.back();
            B.pop_back();
        }
        else if (!B.size()) {
            ans += c - A.back();
            c = A.back();
            A.pop_back();
        }
        else {
            if (c - A.back() <= B.back() - c) {
                ans += c - A.back();
                c = A.back();
                A.pop_back();
            }
            else {
                ans += B.back() - c;
                c = B.back();
                B.pop_back();
            }
        }
        debug(c);
    }

    cout << ans << '\n';

    return 0;
}