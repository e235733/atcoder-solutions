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

    int h, w;
    cin >> h >> w;

    vector<string> S(h);
    rep (i, h) {
        cin >> S[i];
    }

    int count = 0;
    rep (h1, h) {
        rep (w1, w) {
            for (int h2=h1; h2!=h; ++h2) {
                for (int w2=w1; w2!=w; ++w2) {
                    //debug(h1, h2, w1, w2);

                    bool is_ok = true;
                    for (int r=h1; r!=h2+1; ++r) {
                        for (int c=w1; c!=w2+1; ++c) {
                            if (S[r][c] != S[h1+h2-r][w1+w2-c]) {
                                is_ok = false;
                            }
                        }
                    }

                    if (is_ok) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << '\n';

    return 0;
}