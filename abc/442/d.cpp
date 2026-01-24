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

    int n, q;
    cin >> n >> q;

    // 数列
    vector<int> A;
    // 累積和
    vector<ll> sum_a = {0};
    rep (i, n) {
        int a;
        cin >> a;

        A.push_back(a);

        ll sum = sum_a.back() + a;
        sum_a.push_back(sum);
    }
    /*
    cout << "A : ";
    rep (i, n) {
        cout << A.at(i) << ' ';
    }
    cout << endl;
    cout << "sum_A : ";
    rep (i, n+1) {
        cout << sum_a.at(i) << ' ';
    }
    cout << endl;
    */

    // クエリの処理
    rep (i, q) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            // 累積和の値を変更
            ll swapped_sum = sum_a.at(x) + A.at(x) - A.at(x-1);
            sum_a.at(x) = swapped_sum;
            // 数列の値を入れ替え
            int regist = A.at(x-1);
            A.at(x-1) = A.at(x);
            A.at(x) = regist;
        }
        else {
            int l, r;
            cin >> l >> r;
            // 累積和の計算
            ll sum = sum_a.at(r) - sum_a.at(l-1);
            cout << sum << endl;
        }
    }

    return 0;
}