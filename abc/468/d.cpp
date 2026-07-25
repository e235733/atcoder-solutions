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

    string S;
    cin >> S;
    int len = S.size();

    int ans = len * 2 - 1;

    vector<int> odd(len, 0);
    int i = 1;
    while (i*2+1 <= len) {
        debug(i);
        rep (l, len-i*2) {
            int r = l + 2 * i;
            if (S[l] != S[r]) ++odd[l+i];
            if (odd[l+i] <= 1) ++ans;
        }
        debug(odd);
        ++i;
    }

    vector<int> even(len-1, 0);
    rep (k, len-1) {
        if (S[k] != S[k+1]) ++even[k];
    }
    i = 1;
    while (i*2+2 <= len) {
        debug(i);
        rep (l, len-i*2-1) {
            int r = l + 2 * i + 1;
            if (S[l] != S[r]) ++even[l+i];
            if (even[l+i] <= 1) ++ans;
        }
        debug(even);
        ++i;
    }

    cout << ans << '\n';

    return 0;
}