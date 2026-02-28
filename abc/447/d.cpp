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

    string s;
    cin >> s;
    int length = s.size();

    vector<int> idx_a, idx_b, idx_c;
    rep(i, length) {
        char c = s[i];
        if (c == 'A') {
            idx_a.push_back(i);
        }
        else if (c == 'B') {
            idx_b.push_back(i);
        }
        else if (c == 'C') {
            idx_c.push_back(i);
        }
    }
    debug(idx_a);
    debug(idx_b);
    debug(idx_c);

    int result = 0;

    int i_a = 0;
    int i_b = 0;
    int i_c = 0;
    while (i_a != idx_a.size() && i_b != idx_b.size() && i_c != idx_c.size()) {
        if (idx_a[i_a] < idx_b[i_b] && idx_b[i_b] < idx_c[i_c]) {
            debug(i_a, i_b, i_c);
            result++;
            i_a++;
            i_b++;
            i_c++;
        }
        else if (idx_a[i_a] > idx_b[i_b]) {
            i_b++;
        }
        else if (idx_b[i_b] > idx_c[i_c]) {
            i_c++;
        }
    }
    cout << result << '\n';

    return 0;
}