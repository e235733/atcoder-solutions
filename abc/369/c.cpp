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

    vector<int> A(n);
    rep (i, n) {
        cin >> A[i];
    }
    vector<int> d(n-1);
    rep (i, n-1) {
        d[i] = A[i+1] - A[i];
    }

    ll count = n;
    ll pi = 0;
    ll pd = d[0];
    rep (i, n-2) {
        if (d[i+1] != pd) {
            ll dp = i + 1 - pi;
            count += (dp + 1) * dp / 2;
            pi = i + 1;
            pd = d[i+1];
        }
    }
    ll ldp = n - 1 - pi;
    count += (ldp + 1) * ldp / 2;
    
    cout << count << '\n';

    return 0;
}