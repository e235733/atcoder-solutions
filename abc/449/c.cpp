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

    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;

    unordered_map<char, vector<int>> counts;

    int length = s.size();

    rep(i, length) {
        char c = s[i];
        if (counts.contains(c)) {
            counts[c][i] = 1;
        }
        else {
            counts[c] = vector<int>(length, 0);
            counts[c][i] = 1;
        }
    }
    debug(counts);

    // 指定 index 以降に登場するその文字の個数
    for (auto &p : counts) {
        vector<int> &exists = p.second;
        rep (i, length - 1) {
            exists[length-2-i] += exists[length-1-i];
        }
    }
    debug(counts);

    ll result = 0;
    rep (i, length) {
        char c = s[i];
        debug(c);
        debug(i+l, i+r+1);
        if (i+l >= length) {
            continue;
        }
        result += counts[c][min(i+l, length-1)];
        debug(result);
        if (i+r+1 >= length) {
            continue;
        }
        result -= counts[c][min(i+r+1, length-1)];
        debug(result);
    }

    cout << result << '\n';

    return 0;
}