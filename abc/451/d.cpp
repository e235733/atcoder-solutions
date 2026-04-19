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

    int max_digit = 10;

    // 2 の冪乗
    vector<vector<int>> m(max_digit);
    int x = 1;
    int max_x = 1;
    rep (_, max_digit-1) {
        max_x *= 10;
    }
    while (x <= max_x) {
        int left_x = x;
        int digit = 0;
        while (left_x != 0) {
            left_x /= 10;
            digit++;
        }

        m[digit].push_back(x);
        x *= 2;
    }
    debug(m);

    // 各桁の作れる数
    vector<vector<int>> l(max_digit);

    for (int i=1; i!=max_digit; ++i) {
        for (int a : m[i]) {
            l[i].push_back(a);
        }
        
        for (int j=1; j!=i; ++j) {
            // 文字列結合を数値的に行うためにかける値
            int d = 1;
            rep (_, i-j) {
                d *= 10;
            }

            for (int a : l[j]) {
                for (int b : l[i-j]) {
                    l[i].push_back(a * d + b);
                }
            }
        }

        sort(l[i].begin(), l[i].end());
        l[i].erase(unique(l[i].begin(), l[i].end()), l[i].end());
    }
    //debug(l);

    vector<int> result = {0};
    rep (i, max_digit-1) {
        result.insert(result.end(), l[i+1].begin(), l[i+1].end());
    }
    //debug(result);

    int n;
    cin >> n;

    cout << result[n] << '\n';

    return 0;
}