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

    // 番号が小さい連結成分の数
    vector<int> count(n+1, 0);
    rep (_, m) {
        int a, b;
        cin >> a >> b;

        if (a > b) {
            count[a]++;
        }
        else {
            count[b]++;
        }
    }
    debug(count);

    int result = 0;
    rep (i, n+1) {
        if (count[i] == 1) {
            result++;
        }
    }
    cout << result << endl;

    return 0;
}