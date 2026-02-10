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
    debug(n);

    int digit_count = 0;

    // いもす法を用いて、各桁の1の個数を調べる
    vector<int> imos(200005, 0);
    rep (_, n) {
        int a;
        cin >> a;
        imos[a-1]++;
        digit_count = max(a, digit_count);
    }
    // 逆向きに累積する
    int prev_sum = 0;
    rep (i, 200005) {
        imos[200005-1-i] += prev_sum;
        prev_sum = imos[200005-1-i];
    }
    
    int carry = 0;
    // 桁上がりがあれば行う
    rep (i, digit_count) {
        int num_one = imos[i] + carry;
        imos[i] = num_one % 10;
        carry = num_one / 10;
    }
    
    // 最初の桁数を超えた繰り上がりがあるか
    if (carry != 0) {
        // 桁を増やして繰り上げる
        while (carry != 0) {
            imos[digit_count] = carry % 10;
            carry /= 10;
            digit_count++;
        }
    }

    // 後ろから出力する
    rep (i, digit_count) {
        cout << imos[digit_count-1-i];
    }
    cout << endl;

    return 0;
}