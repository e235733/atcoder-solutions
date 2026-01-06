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

    int n, m;
    cin >> n >> m;

    // 逆辺の配列
    vector<vector<int>> to(n+1);
    rep(i, m) {
        int x, y;
        cin >> x >> y;

        to.at(y).push_back(x);
    }

    // 黒の点
    vector<bool> is_black(n+1, false);
    int q;
    cin >> q;

    rep(i, q) {
        int type, v;
        cin >> type >> v;

        if (type == 1) {
            if (is_black.at(v)) {
                continue;
            }
            else {
                vector<int> current_black;
                current_black.push_back(v);
                is_black.at(v) = true;
                // 探索対象がある限り続く
                while (current_black.size() > 0) {
                    // 次の探索対象を保存しておく
                    vector<int> next_black;
                    // 探索対象の全ノードについて調べる
                    for (int current_node : current_black) {
                        // 現在のノードの次のノードについて調べる
                        for (int next_node : to.at(current_node)) {
                            // 次のノードが黒なら飛ばす
                            if (is_black.at(next_node)) {
                                continue;
                            }
                            // 白なら次の探索対象に入れ、黒にする
                            else {
                                next_black.push_back(next_node);
                                is_black.at(next_node) = true;
                            }      
                        }
                    }
                    current_black = next_black;
                }
            }
        }
        else {
            if (is_black.at(v)) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}