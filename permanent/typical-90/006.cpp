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

    int n, k;
    string s;
    cin >> n >> k >> s;

    int len = s.size();
    vector<vector<int>> min_idx(len+1);
    min_idx[len] = vector<int>(26, -1);
    rep (i, len) {
        vector<int> vec = min_idx[len-i];
        int nc = s[len-1-i] - 'a';
        vec[nc] = len-1-i;

        min_idx[len-1-i] = vec;
    }
    debug(min_idx);

    int i = 0;
    int l = k;
    while (l) {
        rep (j, 26) {
            if (min_idx[i][j] == -1) {
                continue;
            }
            if (l > len - min_idx[i][j]) {
                continue;
            }

            cout << s[min_idx[i][j]];
            i = min_idx[i][j] + 1;
            l--;
            break;
        }
    }
    cout << '\n';

    return 0;
}