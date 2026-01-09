#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;

    dsu d(n);

    rep(i, m) {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        d.merge(u, v);
    }

    int group_count = 0;
    rep(i, n) {
        if (d.leader(i) == i) {
            group_count++;
        }
    }

    int result = m - n + group_count;

    cout << result << endl;

    return 0;
}