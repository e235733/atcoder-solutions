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

    int n;
    cin >> n;

    vector<ll> sum_a, sum_b, sum_c, e;
    vector<pair<ll, int>> max_d;
    sum_a.push_back(0);
    rep (i, n) {
        int a;
        cin >> a;
        sum_a.push_back(sum_a.back() + a);
    }
    sum_b.push_back(0);
    rep (i, n) {
        int b;
        cin >> b;
        sum_b.push_back(sum_b.back() + b);
    }
    sum_c.push_back(0);
    rep (i, n) {
        int c;
        cin >> c;
        sum_c.push_back(sum_c.back() + c);
    }
    // i 以下で sum_a - sum_b の最大値とそのときの x
    max_d.push_back({-1000000000, 0});
    rep (i, n) {
        ll current_value = sum_a.at(i+1) - sum_b.at(i+1);
        // 最大値を更新した場合
        if (current_value > max_d.back().first) {
            max_d.push_back({current_value, i+1});
        }
        // 更新しなければ継続
        else {
            max_d.push_back(max_d.back());
        }
    }
    // sum_b - sum_c
    e.push_back(0);
    rep (i, n) {
        e.push_back(sum_b.at(i+1) - sum_c.at(i+1));
    }

    /*
    cout << "sum_a : ";
    rep (i, n+1) {
        cout << sum_a.at(i) << ' ';
    }
    cout << endl;
    cout << "sum_b : ";
    rep (i, n+1) {
        cout << sum_b.at(i) << ' ';
    }
    cout << endl;
    cout << "sum_c : ";
    rep (i, n+1) {
        cout << sum_c.at(i) << ' ';
    }
    cout << endl;
    cout << "max_d : ";
    rep (i, n+1) {
        cout << max_d.at(i).first << ':' << max_d.at(i).second << ' ';
    }
    cout << endl;
    cout << "e : ";
    rep (i, n+1) {
        cout << e.at(i) << ' ';
    }
    cout << endl;
    */

    // max_d[y-1] + e[y] の最大値を求める
    int max_y = 2;
    ll max_value = -1000000000;
    // 2 <= y < n-1 である
    rep (i, n-2) {
        int current_y = i+2;
        ll current_value = max_d.at(current_y-1).first + e.at(current_y);
        // 最大値を更新した場合
        if (current_value > max_value) {
            max_y = current_y;
            max_value = current_value;
        }
    }
    // max_d から d を最大化する x を取得
    int max_x = max_d.at(max_y - 1).second;

    // 答えを求める
    ll result = sum_a.at(max_x) + sum_b.at(max_y) - sum_b.at(max_x) + sum_c.at(n) - sum_c.at(max_y);

    cout << result << endl;

    return 0;
}