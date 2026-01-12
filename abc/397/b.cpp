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

    string s;
    cin >> s;

    int length = s.size();
    // 長さが1のとき
    if (length == 1) {
        cout << 1 << endl;
    }
    else {
        int result = 0;

        for (int i=1; i!=length; ++i) {
            // 連続していたらカウントアップ
            if (s.at(i-1) == s.at(i)) {
                result++;
            }
        }

        // 長さが偶数の場合
        if ((length + result) % 2 == 0) {
            // 最初が o なら先頭に i 末尾に o を追加しなければならない
            if (s.at(0) == 'o') {
                result += 2;
            }
        }
        // 奇数の場合
        else {
            // 先頭か末尾に i か o を追加しなければならない
            result++;
        }

        cout << result << endl;
    }

    return 0;
}