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
    
    vector<int> a(n);
    rep (i, n) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    debug(a);

    int alice = 0;
    int bob = 0;
    rep (i, n) {
        if (i % 2 == 0) {
            alice += a[i];
        }
        else {
            bob += a[i];
        }
    }

    cout << alice - bob << endl;

    return 0;
}