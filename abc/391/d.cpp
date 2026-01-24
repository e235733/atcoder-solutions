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

    int n, w;
    cin >> n >> w;

    // 最初の状態
    vector<map<int, int>> blocks(w+1);
    rep (i, n) {
        int x, y;
        cin >> x >> y;
        blocks.at(x)[y] = i + 1;
    }

    // 列ごとのブロック数の最小値
    int min_num = 1000000000;
    rep(i, w) {
        auto& col = blocks.at(i+1);
        int height = col.size();
        // 最小値の更新
        if (height < min_num) {
            min_num = height;
        }
    }

    // 最大高さが 0 なら、全ての結果が Yes
    if (min_num == 0) {
        int q;
        cin >> q;

        rep(i, q) {
            cout << "Yes" << endl;
        }
        return 0;
    }
    

    // 下から i 番目のブロックの高さの最大値
    vector<int> max_height(min_num+1, 0);
    rep (i, w) {
        auto& col = blocks.at(i+1);
        // 下からの順序
        int order = 1;
        for (auto p : col) {
            // 最大高さの更新
            if (p.first > max_height.at(order)) {
                max_height.at(order) = p.first;
            }
            order++;
            if (order > min_num) {
                break;
            }
        }
    }

    // 各ブロックが消える時刻
    vector<int> rm_time(n+1, 0);
    rep (i, w) {
        auto& col = blocks.at(i+1);
        // 下からの順序
        int order = 1;
        for (auto p : col) {
            // 消える場合
            if (order <= min_num) {
                rm_time.at(p.second) = max_height.at(order);
            }
            // 消えない場合
            else {
                rm_time.at(p.second) = 1000000001;
            }
            order++;
        }
    }

    int q;
    cin >> q;
    // 質問の処理
    rep(i, q) {
        int t, a;
        cin >> t >> a;

        // 時刻が消滅より前なら Yes
        if (t < rm_time.at(a)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}