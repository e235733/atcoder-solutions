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
    string s;
    cin >> n >> s;

    vector<int> vec(2*n);
    int l = n-1;
    int r = n;
    bool fow = true;
    rep (i, n) {
        if (s[i] == 'o') {
            if (fow) {
                vec[l] = i+1;
                --l;
            }
            else {
                vec[r] = i+1;
                ++r;
            }
            fow = !fow;
        }
        else {
            if (fow) {
                vec[l] = i+1;
                --l;
            }
            else {
                vec[r] = i+1;
                ++r;
            }
        }
    }
    debug(fow);
    debug(vec);

    if (fow) {
        for (int i=r-1; i!=l; --i) {
            cout << vec[i] << ' ';
        }
    }
    else {
        for (int i=l+1; i!=r; ++i) {
            cout << vec[i] << ' ';
        }
    }
    cout << '\n';

    return 0;
}