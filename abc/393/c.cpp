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

    // 各点を vector で、各辺とその数を map で表現する
    vector<map<int, int>> g(n+1);
    rep (i, m) {
        int u, v;
        cin >> u >> v;
        // 無向グラフなので、双方にアクセスできる
        g.at(u)[v]++;
        g.at(v)[u]++;
    }

    // 多重辺、ループを数え上げる
    int count = 0;
    rep (i, n) {
        for (auto p : g.at(i+1)) {
            // ループがあったらカウント
            if (p.first == i+1) {
                count += p.second;
            }
            // 別の点に対する辺が複数あったらカウント
            else if (p.second != 1) {
                count += p.second - 1;
            }
        }
    }

    // それぞれ2回カウントしているので、答えはその半分
    cout << count / 2 << endl;

    return 0;
}