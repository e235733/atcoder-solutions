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

    int n;
    cin >> n;

    // 最後に値が登場した位置を記録しておく
    map<int, int> last_position;
    // 最短距離　全て異なる値なら初期値 n + 1 のまま
    int min_distance = n + 1;

    rep (i, n) {
        int a;
        cin >> a;

        // 値がすでに登場している場合
        if (last_position.contains(a)) {
            int distance = i - last_position.at(a) + 1;
            min_distance = min(distance, min_distance);

            last_position.at(a) = i;
        }
        // 初出の場合
        else {
            last_position[a] = i;
        }
    }

    // min_distance が初期値のままの場合
    if (min_distance == n + 1) {
        cout << -1 << endl;
    }
    else {
        cout << min_distance << endl;
    }

    return 0;
}