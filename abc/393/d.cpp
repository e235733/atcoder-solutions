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

    int n;
    string s;

    cin >> n >> s;

    // 1 のインデックスを vector で記録する
    vector<int> position;
    rep (i, n) {
        if (s.at(i) == '1') {
            position.push_back(i);
        }
    }

    // 1 の個数
    int num_one = position.size();
    // 1 をひとかたまりにする範囲を調べる
    // l 以上 r 未満
    int l, r;
    // 偶数個の場合
    if (num_one % 2 == 0) {
        // 中央値以上で最小のインデックス
        int med_i = num_one / 2;
        int median = position.at(med_i);
        l = median - num_one / 2;
        r = median + num_one / 2;
    }
    // 奇数個の場合
    else {
        // 中央値
        int med_i = (num_one - 1) / 2;
        int median = position.at(med_i);
        l = median - (num_one - 1) / 2;
        r = median + (num_one + 1) / 2;
    }

    // それぞれの 1 からまとまりの対応した位置までの距離を足していく
    ll sum_distance = 0;
    rep (i, num_one) {
        sum_distance += abs(l + i - position.at(i));
    }

    cout << sum_distance << endl;

    return 0;
}