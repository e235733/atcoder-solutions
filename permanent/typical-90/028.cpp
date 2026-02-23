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

    const int size = 1000;

    int n;
    cin >> n;

    // いもす法を使う
    vector<vector<int>> imos(size+1, vector<int>(size+1, 0));
    rep (_, n) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        imos[ly][lx]++;
        imos[ly][rx]--;
        imos[ry][lx]--;
        imos[ry][rx]++;
    }
    //debug(imos);
    // x 方向の累積和を求める
    rep (i, size) {
        rep (j, size) {
            imos[i][j+1] = imos[i][j] + imos[i][j+1];
        } 
    }
    // y 方向の累積和を求める
    rep (i, size) {
        rep (j, size) {
            imos[j+1][i] = imos[j][i] + imos[j+1][i];
        }
    }
    //debug(imos);

    // 重なっている枚数ごとの面積を調べる
    vector<int> area_size(n+1, 0);
    rep (i, size) {
        rep (j, size) {
            int num_sheets = imos[i][j];
            area_size[num_sheets]++;
        }
    }
    debug(area_size);

    rep (i, n) {
        cout << area_size[i+1] << '\n';
    }

    return 0;
}