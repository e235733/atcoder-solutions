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

    // puyo をスタックで記録 (a: num)
    // second には、連続数を記録
    stack<pair<int, int>> puyo;

    rep (i, n) {
        int a;
        cin >> a;

        // 直前に値が存在する場合
        if (!puyo.empty()) {
            // 直前の値が a と等しい場合
            if (a == puyo.top().first) {
                // 連続数をインクリメント
                puyo.top().second++;
                // ４連続を確認し、削除する
                if (puyo.top().second == 4) {
                    puyo.pop();
                }
            }
            // 異なる場合
            else {
                // 新しい pair を push
                puyo.push({a, 1});
            }
        }
        // 空の場合
        else {
            // 新しい pair を push
            puyo.push({a, 1});
        }
    }

    // 残りを数え上げる
    int num_left = 0;
    while (!puyo.empty()) {
        num_left += puyo.top().second;
        puyo.pop();
    }

    cout << num_left << endl;

    return 0;
}