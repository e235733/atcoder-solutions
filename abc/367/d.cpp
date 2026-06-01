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

    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> s(n+1);
    s[0] = 0;
    rep (i, n) {
        cin >> A[i];
        s[i+1] = (s[i] + A[i]) % m;
    }
    debug(s);

    unordered_map<int, ll> cr;
    rep (i, n-1) {
        cr[s[i+1]]++;
    }

    ll count = cr[0];
    cr[s[n]]++;
    unordered_map<int, ll> cl;
    cl[s[1]]++;
    
    debug(count);
    rep (i, n-1) {
        debug(i+2);
        debug(cr);
        debug(cl);
        count += cr[s[i+1]] - cl[s[i+1]];
        debug(count);
        
        cl[s[i+2]]++;
        int rem = (s[n] + s[i+1]) % m;
        cr[rem]++;
    }

    cout << count << '\n';

    return 0;
}