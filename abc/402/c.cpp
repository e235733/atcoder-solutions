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

    // 料理に含まれる食材
    vector<vector<int>> dishes(m);
    rep (i, m) {
        int k;
        cin >> k;
        vector<int> ingredients(k);
        rep (j, k) {
            int a;
            cin >> a;
            ingredients[j] = a;
        }
        dishes[i] = ingredients;
    }
    debug(dishes);

    // 食材を食べられるようになる日
    vector<int> dates(n+1);
    rep (i, n) {
        int b;
        cin >> b;
        dates[b] = i+1;
    }
    debug(dates);

    // i 日後に食べられるようになる料理の数
    vector<int> num_edible(n+1, 0);
    for (auto d : dishes) {
        debug(d);
        // 食べられるようになる日の最大値
        int max_date = 0;
        for (int ing : d) {
            if (dates[ing] > max_date) {
                max_date = dates[ing];
            }
        }
        debug(max_date);
        num_edible[max_date]++;
    }
    debug(num_edible);

    // 累積和を求め、出力する
    int sum_edible = 0;
    rep (i, n) {
        sum_edible += num_edible[i+1];
        cout << sum_edible << endl;
    }

    return 0;
}