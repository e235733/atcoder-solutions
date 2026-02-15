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

    string n;
    int k;
    cin >> n >> k;
    debug(n, k);

    string str8 = n;
    rep (_, k) {
        if (str8 == "0") {
            cout << 0 << endl;
            return 0;
        }
        // 10 進数に変換
        ll num10 = 0;
        int digit8 = str8.size();
        rep (i, digit8) {
            num10 *= 8;
            int num8_i = str8[i] - '0';
            num10 += num8_i;
        }
        debug(num10);
        // 9 進数の文字列に変換
        string str9 = "";
        while (num10 != 0) {
            int num9_i = num10 % 9;
            str9 += num9_i + '0';
            num10 /= 9;
        }
        reverse(str9.begin(), str9.end());
        debug(str9);

        int digit9 = str9.size();
        rep (i, digit9) {
            if (str9[i] == '8') {
                str9[i] = '5';
            }
        }
        debug(str9);

        str8 = str9;
    }

    cout << str8 << endl;

    return 0;
}