#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n, k;
    ll x;
    cin >> n >> k >> x;

    vector<int> A;
    rep (i, n) {
        int a;
        cin >> a;
        A.push_back(a);
    }

    // 降順にソートする
    sort(A.rbegin(), A.rend());

    // x を超えたか
    bool is_over = false;
    // 何杯で超えたか
    int num_cup;

    // n - k 番目以降を見ることで大きい順に見ていくことで、最低の合計を調べる
    ll sum_v = 0;
    rep (i, k) {
        sum_v += A.at(n-k+i);
        // 合計が x を超えたら終了
        if (sum_v >= x) {
            is_over = true;
            num_cup = i + 1;
            break;
        }
    }

    // 超えた場合
    if (is_over) {
        // 水と日本酒のごうけいを出力
        cout << n - k + num_cup << endl;
    }
    else {
        cout << -1 << endl;
    }


    return 0;
}