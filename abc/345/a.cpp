#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    
    if (s[0] != '<' || s[len-1] != '>') {
        cout << "No" << '\n';
        return 0;
    }

    for (int i=1; i!=len-1; ++i) {
        if (s[i] != '=') {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';

    return 0;
}