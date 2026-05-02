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

    vector<string> A(h);
    rep (i, h) {
        cin >> A[i];
    }

    int s_r, s_c, g_r, g_c;
    rep (i, h) {
        rep (j, w) {
            if (A[i][j] == 'S') {
                s_r = i;
                s_c = j;
            }
            else if (A[i][j] == 'G') {
                g_r = i;
                g_c = j;
            }
        }
    }

    vector<int> d_r = {-1, 1, 0, 0};
    vector<int> d_c = {0, 0, -1, 1};

    vector<vector<bool>> used_f(h, vector<bool>(w, false)), used_b(h, vector<bool>(w, false));
    used_f[s_r][s_c] = true;
    vector<int> R = {s_r};
    vector<int> C = {s_c};
    vector<bool> is_forward = {true};
    int count = 0;
    while (R.size()) {
        debug(R);
        debug(C);
        count++;
        int num_current = R.size();
        vector<int> next_R, next_C;
        vector<bool> next_is_forward;
        rep (i, num_current) {
            int r = R[i];
            int c = C[i];
            int f = is_forward[i];

            rep (j, 4) {
                int n_r = r + d_r[j];
                int n_c = c + d_c[j];

                if (n_r < 0 || n_r >= h || n_c < 0 || n_c >= w) {
                    continue;
                }
                debug(n_r, n_c, A[n_r][n_c]);
                if (n_r == g_r && n_c == g_c) {
                    cout << count << '\n';
                    return 0;
                }
                if (A[n_r][n_c] == '#' || (f && A[n_r][n_c] == 'x') || (!f && A[n_r][n_c] == 'o')) {
                    continue;
                }
                if ((f && used_f[n_r][n_c]) || (!f && used_b[n_r][n_c])) {
                    continue;
                }

                if (f) {
                    used_f[n_r][n_c] = true;
                }
                else {
                    used_b[n_r][n_c] = true;
                }

                next_R.push_back(n_r);
                next_C.push_back(n_c);

                if (A[n_r][n_c] == '?') {
                    next_is_forward.push_back(!f);
                }
                else {
                    next_is_forward.push_back(f);
                }
            }
        }
        R = next_R;
        C = next_C;
        is_forward = next_is_forward;
    }

    cout << -1 << '\n';

    return 0;
}