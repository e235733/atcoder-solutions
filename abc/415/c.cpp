#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

// 深さ優先探索する再帰関数
bool can_mixed_all(vector<vector<int>> &to, vector<bool> &has_visited, int node, int goal) {
    bool is_reached = false;
    rep (i, to[node].size()) {
        int next_node = to[node][i];
        // 訪問済みならスキップ
        if (has_visited[next_node]) {
            continue;
        }
        // 訪問済みにする
        has_visited[next_node] = true;
        // 到達したら終了
        if (next_node == goal) {
            return true;
        }
        else {
            // 再帰呼び出し
            is_reached = can_mixed_all(to, has_visited, next_node, goal);
            if (is_reached) {
                return true;
            }
        }
    }
    // 到達しなければここまで来る
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;
    rep (_, t) {
        int n;
        string s;
        cin >> n >> s;
        debug(n, s);

        int num_node = pow(2, n) - 1;

        // 全ての薬品を混ぜた状態がダメなら即終了で次のケースへ
        if (s[num_node-1] == '1') {
            cout << "No" << endl;
            continue;
        }
        // 薬品の混ぜ方を有向グラフにする
        vector<vector<int>> to(num_node, vector<int>());
        rep (i, num_node) {
            // 状態
            int node = i;
            debug(node);
            rep (j, n) {
                // 特定の薬品単体の値を大きい順に見る
                int drug = pow(2, n-j-1);
                debug(drug);
                if (node >= drug) {
                    node -= drug;
                    debug("has mixed");
                }
                // まだ混ぜられていない薬品を混ぜる
                else {
                    debug("has not mixed");
                    int next_state = i + drug;
                    debug(next_state);
                    to[i].push_back(next_state);
                }
            }
        }
        debug(to);

        // 危険な状態のノードを空配列にする 
        rep (i, num_node) {
            if (s[i] == '1') {
                to[i+1] = {};
            }
        }
        debug(to);

        // 訪問済みのノード
        vector<bool> has_visited(num_node, false);
        // 深さ優先探索し、状態 0 から 2^(n-1)まで到達できるか調べる
        if (can_mixed_all(to, has_visited, 0, num_node)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}