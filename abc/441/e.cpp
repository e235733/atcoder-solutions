#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    string s;

    cin >> n >> s;

    // sum_a - sum_b を d とし、その累積和を求める
    vector<int> sum_d(n+1, 0);
    rep (i, n) {
        if (s.at(i) == 'A') {
            sum_d.at(i+1) = sum_d.at(i) + 1;
        }
        else if (s.at(i) == 'B') {
            sum_d.at(i+1) = sum_d.at(i) - 1;
        }
        else {
            sum_d.at(i+1) = sum_d.at(i);
        }
    }
    //rep(i, n+1) {
    //    cout << sum_d.at(i) << ' ';
    //}
    //cout << endl;

    ll count = 0;
    // fenfick_tree で解く
    // sum_d は -n から n まで考えられる
    fenwick_tree<int> fw(n*2+1);
    
    rep(i, n+1) {
        // 範囲は 0 からにしなければならないので、値は sum_d+n
        int current_val = sum_d.at(i) + n;
        // 過去に登場したより小さい値の数を加算
        count += fw.sum(0, current_val);
        // 登録
        fw.add(current_val, 1);
    }

    cout << count << endl;

    return 0;
}