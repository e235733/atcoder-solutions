#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;

    // N_i における利害関係者の人数
    vector<int> num_inv(n+1, 0);
    rep (i, m) {
        int a, b;
        cin >> a >> b;
        num_inv.at(a)++;
        num_inv.at(b)++;
    }

    // 利害関係者以外の組み合わせを求める
    rep (i, n) {
        // 自分と関係者を除く
        int num_not_inv = n - num_inv.at(i+1) - 1;
        ll num_combination = 1LL * num_not_inv * (num_not_inv-1) * (num_not_inv-2) / 6;
        cout << num_combination << endl;
    }

    return 0;
}