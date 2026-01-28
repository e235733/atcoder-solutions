#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    // p と sum_d の初期状態を作成するために、最初の人を追加する
    int first_x;
    cin >> first_x;
    // map で 位置 と d を管理 map<(x), (d)>
    map<int, int> p = {{0, first_x}, {first_x, first_x}};
    int sum_d = first_x * 2;
    cout << sum_d << endl;

    rep (_, n-1) {
        int x;
        cin >> x;

        // current_x より大きい最小の x のイテレータを取得
        auto upper = p.upper_bound(x);
        // current_x の両側の x との距離
        int d_l, d_r = 1000000000;
        // upper はないかもしれないので存在を確認
        if (upper != p.end()) {
            // 距離の更新
            d_r = upper->first - x;
            if (d_r < upper->second) {
                sum_d += d_r - upper->second;
                upper->second = d_r;
            }
        }
        // 下側との距離の更新
        d_l = x - prev(upper)->first;
        if (d_l < prev(upper)->second) {
            sum_d += d_l - prev(upper)->second;
            prev(upper)->second = d_l;
        }

        // 値の保存と sum_d の更新
        int x_d = min(d_l, d_r);
        p[x] = x_d;
        sum_d += x_d;
        cout << sum_d << endl;
    }

    return 0;
}