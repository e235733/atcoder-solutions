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

    int n, a, b;
    cin >> n >> a >> b;

    // a, b の個数の累積和
    vector<int> sum_a = {0}, sum_b = {0};
    rep (i, n) {
        char a;
        cin >> a;

        if (a == 'a') {
            sum_a.push_back(sum_a.back() + 1);
            sum_b.push_back(sum_b.back());
        }
        else {
            sum_a.push_back(sum_a.back());
            sum_b.push_back(sum_b.back() + 1);
        }
    }
    debug(sum_a);
    debug(sum_b);

    // i を l と固定したとき、a の個数が条件を満たすようになる最小の r
    vector<int> a_r(n, 0);
    int l = 0;
    int r = 1;
    // a_r を埋めていく
    while (r <= n) {
        while (r <= n) {
            // a の個数が条件を満たす
            if (sum_a.at(r) - sum_a.at(l) == a) {
                a_r.at(l) = r;
                break;
            }
            else {
                r++;
            }
        }
        l++;
    }
    debug(a_r);

    // b の個数が上限を満たさなくなる最小の r
    // r > n の分は、全て条件を満たすということになるので n + 1 
    vector<int> b_r(n, n + 1);
    l = 0;
    r = 1;
    // a_r を埋めていく
    while (r <= n) {
        while (r <= n) {
            // b の個数が条件を満たさない
            if (sum_b.at(r) - sum_b.at(l) == b) {
                b_r.at(l) = r;
                break;
            }
            else {
                r++;
            }
        }
        l++;
    }
    debug(b_r);
    
    ll count = 0;
    // lを固定した場合、 b_r - a_r が条件を満たす数になる。
    // ただし、a_r != 0 && b_r > a_r のときのみ
    rep (i, n) {
        // a_r が 0 のとき、それ以降条件を満たすものはないので終了
        if (a_r.at(i) == 0) {
            break;
        }
        else if (b_r.at(i) > a_r.at(i)) {
            count += b_r.at(i) - a_r.at(i);
        }
    }

    cout << count << endl;

    return 0;
}