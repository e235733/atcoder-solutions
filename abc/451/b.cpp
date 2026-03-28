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

    int n, m;
    cin >> n >> m;

    vector<int> diff(m, 0);

    rep (i, n) {
        int a, b;
        cin >> a >> b;

        diff[a-1]--;
        diff[b-1]++;
    }
    debug(diff);

    rep (i, m) {
        cout << diff[i] << '\n';
    }

    return 0;
}