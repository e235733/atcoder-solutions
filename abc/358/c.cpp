#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int inf = 1 << 30;

int n, m;
vector<string> s(10);

int ms = inf;

void dfs (int c, int ns, vector<bool> t) {
    if (c == n) {
        bool ok = true;
        rep(i, m) {
            if (!t[i]) {
                ok = false;
                break;
            }
        }
        if (ok) ms = min(ms, ns);
        return; 
    }

    dfs (c+1, ns, t);
    rep (i, m) {
        t[i] = t[i] || s[c][i] == 'o';
    }
    dfs (c+1, ns+1, t);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> m;
    rep (i, n) cin >> s[i];

    vector<bool> t(m, false);
    dfs (0, 0, t);

    cout << ms << '\n';

    return 0;
}