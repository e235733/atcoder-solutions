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

    for (int w=1; w!=len; ++w) {
        rep (c, w) {
            string p = "";
            for (int i=c; i<len; i+=w) {
                p.push_back(s[i]);
            }

            if (p == t) {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    
    cout << "No" << '\n';

    return 0;
}