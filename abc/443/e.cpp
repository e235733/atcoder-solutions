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

    int t;
    cin >> t;

    vector<int> d_c = {-1, 0, 1};

    rep (_, t) {
        int n, c;
        cin >> n >> c;
        c--;
        vector<string> s(n);
        rep (i, n) {
            cin >> s[i];
        }

        vector<queue<int>> wall(n);
        rep (i, n) {
            rep (j, n) {
                if (s[n-j-1][i] == '#') {
                    wall[i].push(n-j-1);
                }
            }
        }
        debug(wall);

        int r = n - 1;
        unordered_set<int> ok;
        ok.insert(c);
        while (r != 0) {
            debug(r, ok);
            unordered_set<int> next_ok;
            for (int current : ok) {
                rep (i, 3) {
                    int n_c = current + d_c[i];
                    if (n_c < 0 || n_c >= n) {
                        continue;
                    }

                    if (next_ok.contains(n_c)) {
                        continue;
                    }

                    if (s[r-1][n_c] == '.') {
                        next_ok.insert(n_c);
                    }
                    else {
                        if (wall[n_c].front() != r-1) {
                            continue;
                        }

                        next_ok.insert(n_c);
                        wall[n_c].pop();
                    }
                }
            }
            ok = next_ok;
            r--;
        }
        debug(ok);

        vector<bool> result(n, false);
        for (int o : ok) {
            result[o] = true;
        }

        rep (i, n) {
            cout << result[i];
        }
        cout << '\n';
    }

    return 0;
}