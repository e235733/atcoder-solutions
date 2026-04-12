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

    int h, w, d;
    cin >> h >> w >> d;

    vector<string> S(h);
    rep(i, h) {
        cin >> S[i];
    }

    int result = 0;
    rep (r0, h) {
        rep (c0, w) {
            rep (r1, h) {
                rep (c1, w) {
                    if (S[r0][c0] == '#' || S[r1][c1] == '#') {
                        continue;
                    }
                    debug(r0, c0, r1, c1);
                    int count = 0;
                    rep (r, h) {
                        rep (c, w) {
                            debug(r, c);
                            if (S[r][c] == '#') {
                                continue;
                            }

                            int dist0 = abs(r0 - r) + abs(c0 - c);
                            int dist1 = abs(r1 - r) + abs(c1 - c);
                            debug(dist0, dist1);
                            if (dist0 > d && dist1 > d) {
                                continue;
                            }

                            count++;
                        }
                    }
                    debug(count);
                    result = max(result, count);
                }
            }
        }
    }
    cout << result << '\n';

    return 0;
}