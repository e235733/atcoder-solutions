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

    int len = s.size();
    vector<string> result;
    vector<int> b;
    rep (i, len) {
        if (s[i] == t[i]) {
            continue;
        }

        if (s[i] - t[i] > 0) {
            s[i] = t[i];
            result.push_back(s);
        }
        else {
            b.push_back(i);
        }
    }
    debug(result);
    debug(b);

    reverse(b.begin(), b.end());
    for (int i : b) {
        s[i] = t[i];
        result.push_back(s);
    }

    cout << result.size() << '\n';
    for (string r : result) {
        cout << r << '\n';
    }

    return 0;
}