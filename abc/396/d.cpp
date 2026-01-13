#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

// 再帰関数
void recurse(vector<vector<pair<int, ll>>>& g, set<int>& is_visited, int num_node, int node, ll& min_val, ll prev_val) {
    //cout << "now on " << node << endl;
    for (auto p : g.at(node)) {
        // まだ訪れていないノードのみ進む
        if (!is_visited.contains(p.first)) {
            is_visited.insert(p.first);
            ll current_val = prev_val ^ p.second;
            //cout << "current value : " << current_val << endl;

            // n 以外の場合
            if (p.first != num_node) {
                // 再帰
                recurse(g, is_visited, num_node, p.first, min_val, current_val);
            }
            // n の場合、つまりゴールした際の処理
            else {
                // 最小値の計算
                min_val = min(min_val, current_val);

                //cout << "reached to goal!" << endl;
                //cout << "min value : " << min_val << endl;
            }
            is_visited.erase(p.first);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;

    // グラフ
    vector<vector<pair<int, ll>>> g(n, vector<pair<int, ll>>());
    rep (i, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        // アクセス先と w の値を pair にして保存する
        pair<int, ll> p = {v, w};
        g.at(u).push_back(p);
        // 逆向きも作るが、4 からは出さず 1 にも向かわせない
        pair<int, ll> rp = {u, w};
        if (v != n && u != 1) {
            g.at(v).push_back(rp);
        }
    }

    // 訪問済みのノードを記録しておく
    set<int> is_visited;
    is_visited.insert(1);

    // 最小値を記録しておく
    ll min_val = pow(2, 60);
    ll prev_val = 0;

    recurse(g, is_visited, n, 1, min_val, 0);

    cout << min_val << endl;

    return 0;
}