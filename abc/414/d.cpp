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

    // 全ての家に電波塔を配置できる場合は即終了
    if (n == m) {
        cout << 0 << endl;
        return 0;
    }

    // 家の座標
    vector<ll> house(n);
    rep (i, n) {
        ll x;
        cin >> x;
        house[i] = x;
    }
    // ソートする
    sort(house.begin(), house.end());
    debug(house);
    // 最初の家から最後の家までの距離
    ll max_dist = house.back() - house.front();
    debug(max_dist);

    // 隣り合う家どうしの距離
    vector<ll> dist(n-1);
    rep (i, n-1) {
        dist[i] = house[i+1] - house[i];
    }
    // 降順にソートする
    sort(dist.rbegin(), dist.rend());
    debug(dist);

    // dist を大きい順に m-1 個ひく
    ll result = max_dist;
    rep (i, m-1) {
        result -= dist[i];
    }

    cout << result << endl;

    return 0;
}