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

    int len = s.size();
    if (len % 2 == 1) {
        cout << "No" << '\n';
        return 0;
    }

    vector<int> count(256);
    char prev;
    rep (i, len) {
        if (i % 2 == 0) {
            if (count[s[i]] == 2) {
                cout << "No" << '\n';
                return 0;
            }
            count[s[i]]++;
            prev = s[i];
        }
        else {
            if (s[i] != prev) {
                cout << "No" << '\n';
                return 0;
            }
            count[s[i]]++;
        }
    }
    cout << "Yes" << '\n';

    return 0;
}