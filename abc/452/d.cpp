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

    string s, t;
    cin >> s >> t;

    int len_s = s.size();
    int len_t = t.size();

    int l = 0;
    int r = 0;
    // 探索対象の部分列の idx
    int i = 0;
    vector<int> L, R;
    while (r != len_s) {
        if (s[r] == t[i]) {
            i++;
            if (i == len_t) {
                debug(l, r);
                L.push_back(l);
                R.push_back(r);
                i = 0;

                l = r + 1;
                int r_i = len_t - 1;
                while (r_i != -1) {
                    l--;
                    if (s[l] == t[r_i]) {
                        r_i--;
                    }
                }
                r = l;
                l++;
            }
        }
        r++;
    }
    L.push_back(l);
    R.push_back(r);
    debug(L);
    debug(R);

    int num_block = L.size();
    ll result = 0;
    rep (i, num_block) {
        if (i != 0) {
            int len_duplicated_block = R[i-1] - L[i];
            result -= 1LL * (len_duplicated_block + 1) * len_duplicated_block / 2;
        }
        int len_block = R[i] - L[i];
        result += 1LL * (len_block + 1) * len_block / 2;
    }

    cout << result << '\n';

    return 0;
}