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

    int n, r, c;
    string s;
    cin >> n >> r >> c >> s;

    // 焚き火の位置を記録しておく {y座標, x座標}
    pair<int, int> pos_fire = {0, 0};
    // r, c の位置も同様に記録しておく
    pair<int, int> pos_observe = {r, c};

    // 煙の位置を記録しておく
    set<pair<int, int>> pos_smoke;
    pos_smoke.insert(pos_fire);

    rep(i, n) {
        char q = s.at(i);
        // 各文字ごとに、煙の移動とは逆方向に焚き火と観測の位置を動かす
        if (q == 'N') {
            pos_fire.first += 1;
            pos_observe.first += 1;
        }
        else if (q == 'W') {
            pos_fire.second += 1;
            pos_observe.second += 1;
        }
        else if (q == 'S') {
            pos_fire.first -= 1;
            pos_observe.first -= 1;
        }
        else if (q == 'E') {
            pos_fire.second -= 1;
            pos_observe.second -=1;
        }

        // 煙を追加する
        pos_smoke.insert(pos_fire);

        if (pos_smoke.contains(pos_observe)) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    cout << endl;
    
    return 0;
}