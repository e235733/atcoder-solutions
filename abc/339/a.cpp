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

    string t = "";
    for (int i=len-1; i!=-1; --i) {
        if (s[i] == '.') break;

        t.push_back(s[i]);
    }
    reverse(t.begin(), t.end());

    cout << t << '\n';

    return 0;
}