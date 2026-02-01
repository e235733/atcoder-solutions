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
    debug(n, m);
    vector<int> c(n+1);
    rep (i, n) {
        int c_i;
        cin >> c_i;
        c[i+1] = c_i;
    }
    debug(c);
    
    vector<vector<int>> a(m);
    rep (i, m) {
        int k;
        cin >> k;
        vector<int> a_i(k);
        rep(j, k) {
            int a_ij;
            cin >> a_ij;
            a_i[j] = a_ij;
        }
        a[i] = a_i;
    }
    debug(a);
    // 動物園ごとの動物
    vector<vector<int>> z(n+1, vector<int>(m, 0));
    rep (i, m) {
        for (int z_i : a[i]) {
            z[z_i][i]++;
        }
    }
    debug(z);

    // 動的計画法
    vector<pair<pair<ll, vector<int>>, bool>> dp;
    dp.push_back({{0, vector<int>(m, 0)}, true});

    rep (ani_i, m) {
        debug(ani_i);
        int len_dp = (int)dp.size();
        rep (p_i, len_dp) {
            auto p = dp[p_i];
            debug(p);
            // false のものはスルー
            debug(p.second);
            if (!p.second) {
                continue;
            }
            vector<int> &num_a = p.first.second;
            // 対象の動物が 2 以上ならそのまま
            debug(num_a[ani_i]);
            if (num_a[ani_i] >= 2) {
                continue;
            } 
            // 1の場合
            if (num_a[ani_i] == 1) {
                // 動物 ani_i の増やし方を探索する
                for (int a_i=0; a_i!=(int)a[ani_i].size(); ++a_i) {
                    debug(a[ani_i][a_i]);
                    pair<ll, vector<int>> nd_first = p.first;
                    // 動物園の価格を上乗せ
                    nd_first.first += c[a[ani_i][a_i]];
                    rep (k, m) {
                        nd_first.second[k] += z[a[ani_i][a_i]][k];
                    }
                    dp.push_back({nd_first, true});
                    debug(nd_first);
                }
            }
            // 0 の場合
            else {
                // 動物 ani_i を2回増やす
                for (int a_i=0; a_i!=(int)a[ani_i].size(); ++a_i) {
                    debug(a[ani_i][a_i]);
                    pair<ll, vector<int>> nd_first = p.first;
                    // 動物園の価格を上乗せ
                    nd_first.first += c[a[ani_i][a_i]];
                    rep (k, m) {
                        nd_first.second[k] += z[a[ani_i][a_i]][k];
                    }
                    for (int a_j=a_i; a_j!=(int)a[ani_i].size(); ++a_j) {
                        debug(a[ani_i][a_j]);
                        pair<ll, vector<int>> nd_second = nd_first;
                        // 動物園の価格を上乗せ
                        nd_second.first += c[a[ani_i][a_j]];
                        rep (k, m) {
                            nd_second.second[k] += z[a[ani_i][a_j]][k];
                        }
                        dp.push_back({nd_second, true});
                        debug(nd_second);
                    }
                }
            }
            // 今後条件を満たすことはないので falseに
            dp[p_i].second = false;
        }
        debug(dp);
    }

    // 最安のものを探す
    ll min_value = 1000000000000000000;
    for (auto p : dp) {
        // 無効なものはスルー
        if (!p.second) {
            continue;
        }
        min_value = min(p.first.first, min_value);
    }

    cout << min_value << endl;

    return 0;
}