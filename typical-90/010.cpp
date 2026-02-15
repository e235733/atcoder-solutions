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

    int n;
    cin >> n;

    // 各クラスの点数の累積和
    vector<int> sum_1(n+1);
    vector<int> sum_2(n+1);
    sum_1[0] = 0;
    sum_2[0] = 0;

    rep (i, n) {
        int c, p;
        cin >> c >> p;
        debug(c, p);
        if (c == 1) {
            sum_1[i+1] = sum_1[i] + p;
            sum_2[i+1] = sum_2[i];
        }
        else {
            sum_1[i+1] = sum_1[i];
            sum_2[i+1] = sum_2[i] + p;
        }
    }
    debug(sum_1);
    debug(sum_2);

    int q;
    cin >> q;
    
    rep (i, q) {
        int l, r;
        cin >> l >> r;
        int a = sum_1[r] - sum_1[l-1];
        int b = sum_2[r] - sum_2[l-1];
        cout << a << ' ' << b << endl;
    }

    return 0;
}