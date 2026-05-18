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

    int n;
    string s;
    cin >> n >> s;

    vector<pair<int, int>> m2(n+1, {0, 0});
    rep (i, n) {
        if (s[i] == '0') {
            m2[i+1].first = m2[i].second;
            m2[i+1].second = m2[i].first + 1;
        }
        else {
            m2[i+1].first = m2[i].first + 1;
            m2[i+1].second = m2[i].second;
        }
    }
    debug(m2);
    
    ll result = 0;
    rep (i, n) {
        result += m2[i+1].first;
    }
    cout << result << '\n';

    return 0;
}