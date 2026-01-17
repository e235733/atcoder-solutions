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

    // 文字列のインデックス
    int i = 0;
    // インデックスの最大値
    int max_i = 0;

    while (i < s.size() - 1) {
        // i 文字目が 'W' かつ i+1 文字目が 'A' だった場合
        if (s.at(i) == 'W' && s.at(i+1) == 'A') {
            // AC に置換
            s.at(i) = 'A';
            s.at(i+1) = 'C';
            // 最大インデックスの更新
            max_i = max(max_i, i);

            // AC に変わったことで直前が WA になっているかもしれない
            // 前が存在しないので進める
            if (i == 0) {
                i = max(i+1, max_i);
            }
            // デクリメントして前を調べる
            else {
                i--;
            }
        }
        else {
            i = max(i+1, max_i);
        }
    }

    cout << s << endl;

    return 0;
}